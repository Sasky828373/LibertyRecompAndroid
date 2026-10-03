package com.libertyrecomp;

import android.content.Context;
import android.os.Process;
import android.util.Log;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Enumeration;
import java.util.HashSet;
import java.util.Set;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

/**
 * Chooses the Vulkan driver once per process, before SDL loads libmain.so.
 *
 * <p>The runtime opens Vulkan with a bare {@code dlopen("libvulkan.so")}. The
 * APK ships its own libvulkan.so (os/android/native, built on libadrenotools)
 * in nativeLibraryDir, which is searched before the system namespace, so that
 * lookup always lands on the proxy - whether or not anyone loaded it. The proxy
 * is therefore always loaded and always initialized: "turnip" hands it the
 * bundled Mesa Turnip build, "system" forwards to /system/lib64/libvulkan.so.</p>
 *
 * <p>Turnip is the default: the stock Adreno 650 driver exposes a Vulkan 1.1
 * device and the native renderer needs 1.2. {@code driver.txt} next to
 * {@code args.txt} selects "system" instead.</p>
 *
 * <p>Ported from andrewnakas/skate3-android (MIT), which took it from
 * AlanConstantino/skate3-pocket; native/PROVENANCE.md has the details.</p>
 */
final class DriverBridge {

    static final String TURNIP = "turnip";
    static final String SYSTEM = "system";

    private static final String TAG = "LibertyDriver";
    private static final String BUNDLE_ASSET = "drivers/turnip-t30.zip";
    private static final String LIBRARY = "vulkan.purple.so";
    private static final String META = "meta.json";
    private static final String ZIP_HASH =
            "f65b2d3353fd4aa7190bb5426b94468e99ffea7a58a830bc0c4651db89353227";
    private static final String LIB_HASH =
            "1d80dfa019659b008e4669311db5b1e4a02af59ff1d5458a98e2f5fe18ed013b";
    private static final String META_HASH =
            "bf6c432ffd05a254a9531920f6ec826abb2bcf91c52a0c5467167a0ee1940f73";

    private static boolean sInitialized;

    private DriverBridge() {}

    static native String nativeInit(String nativeLibraryDir, String internalDriverDir,
                                    String driverFilename, boolean custom);

    /** Loads and initializes the proxy. Returns the native status JSON. */
    static synchronized String initialize(Context context, String mode) {
        if (sInitialized) {
            return "{\"ok\":true,\"note\":\"already initialized\"}";
        }
        String nativeDir = context.getApplicationInfo().nativeLibraryDir;
        boolean custom = TURNIP.equals(mode);
        File driverDir = new File(context.getFilesDir(), "drivers");
        if (custom) {
            try {
                driverDir = prepareBundle(context);
            } catch (IOException | RuntimeException e) {
                Log.e(TAG, "Turnip bundle unusable, using the system driver", e);
                custom = false;
            }
        }
        if (!driverDir.isDirectory() && !driverDir.mkdirs()) {
            Log.w(TAG, "cannot create " + driverDir);
        }
        System.load(new File(nativeDir, "libvulkan.so").getAbsolutePath());
        String status = nativeInit(nativeDir, driverDir.getAbsolutePath(),
                custom ? LIBRARY : "", custom);
        sInitialized = true;
        boolean ok = false;
        try {
            ok = new JSONObject(status).optBoolean("ok", false);
        } catch (JSONException ignored) {
        }
        if (ok) {
            Log.i(TAG, "driver ready: " + status);
        } else {
            Log.e(TAG, "driver failed: " + status);
        }
        return status;
    }

    /** Extracts the hash-pinned two-file Turnip package into private storage. */
    private static File prepareBundle(Context context) throws IOException {
        File parent = new File(context.getFilesDir(), "drivers");
        File destination = new File(parent, "t30-" + LIB_HASH.substring(0, 12));
        if (valid(new File(destination, LIBRARY), LIB_HASH)
                && valid(new File(destination, META), META_HASH)) {
            return destination;
        }
        if (!parent.isDirectory() && !parent.mkdirs()) {
            throw new IOException("cannot create " + parent);
        }
        File archive = File.createTempFile("turnip-t30-", ".zip", context.getCacheDir());
        File staging = new File(parent, ".t30-staging-" + Process.myPid());
        try {
            try (InputStream in = context.getAssets().open(BUNDLE_ASSET);
                 OutputStream out = new FileOutputStream(archive)) {
                copy(in, out);
            }
            if (!ZIP_HASH.equals(digest(archive))) {
                throw new IOException("bundled Turnip archive failed its integrity check");
            }
            deleteRecursively(staging);
            if (!staging.mkdirs()) {
                throw new IOException("cannot create " + staging);
            }
            try (ZipFile zip = new ZipFile(archive)) {
                Set<String> names = new HashSet<>();
                for (Enumeration<? extends ZipEntry> e = zip.entries(); e.hasMoreElements(); ) {
                    names.add(e.nextElement().getName());
                }
                Set<String> expected = new HashSet<>();
                expected.add(META);
                expected.add(LIBRARY);
                if (!names.equals(expected)) {
                    throw new IOException("unexpected Turnip archive members: " + names);
                }
                extract(zip, META, new File(staging, META), META_HASH);
                extract(zip, LIBRARY, new File(staging, LIBRARY), LIB_HASH);
            }
            deleteRecursively(destination);
            if (!staging.renameTo(destination)) {
                throw new IOException("cannot activate " + destination);
            }
            return destination;
        } finally {
            if (!archive.delete()) {
                archive.deleteOnExit();
            }
            deleteRecursively(staging);
        }
    }

    private static void extract(ZipFile zip, String name, File target, String hash)
            throws IOException {
        try (InputStream in = zip.getInputStream(zip.getEntry(name));
             OutputStream out = new FileOutputStream(target)) {
            copy(in, out);
        }
        if (!valid(target, hash)) {
            throw new IOException(name + " failed its integrity check");
        }
        if (!target.setReadOnly()) {
            throw new IOException("cannot protect " + target);
        }
    }

    private static boolean valid(File file, String hash) {
        try {
            return file.isFile() && hash.equals(digest(file));
        } catch (IOException e) {
            return false;
        }
    }

    private static String digest(File file) throws IOException {
        MessageDigest sha;
        try {
            sha = MessageDigest.getInstance("SHA-256");
        } catch (NoSuchAlgorithmException e) {
            throw new IOException(e);
        }
        try (InputStream in = new FileInputStream(file)) {
            byte[] buffer = new byte[64 * 1024];
            int read;
            while ((read = in.read(buffer)) > 0) {
                sha.update(buffer, 0, read);
            }
        }
        StringBuilder hex = new StringBuilder();
        for (byte b : sha.digest()) {
            hex.append(String.format("%02x", b & 0xff));
        }
        return hex.toString();
    }

    private static void copy(InputStream in, OutputStream out) throws IOException {
        byte[] buffer = new byte[64 * 1024];
        int read;
        while ((read = in.read(buffer)) > 0) {
            out.write(buffer, 0, read);
        }
    }

    private static void deleteRecursively(File file) {
        File[] children = file.listFiles();
        if (children != null) {
            for (File child : children) {
                deleteRecursively(child);
            }
        }
        if (file.exists()) {
            file.setWritable(true);
            file.delete();
        }
    }
}
