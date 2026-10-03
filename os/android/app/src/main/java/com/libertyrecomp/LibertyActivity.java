package com.libertyrecomp;

import android.content.pm.PackageInfo;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.system.ErrnoException;
import android.system.Os;
import android.util.Log;
import android.view.View;
import android.view.WindowManager;

import org.libsdl.app.SDLActivity;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

/**
 * Hosts the Graine RexGlue runtime.
 *
 * <p>SDL owns the window, the event loop and the native thread. Before SDL
 * loads libmain.so this class only prepares what the runtime reads from the
 * environment:</p>
 * <ul>
 *   <li>{@code XDG_DATA_HOME} - the app's external files directory. The title
 *       keeps everything under {@code LibertyRecomp/} there, so the game is
 *       pushed to {@code /sdcard/Android/data/com.libertyrecomp/files/LibertyRecomp/game}
 *       without any storage permission.</li>
 *   <li>{@code REX_RESOURCES_DIR} - fonts, button prompts and the RPF key,
 *       copied out of the APK on the first launch of each install.</li>
 *   <li>{@code args.txt} next to {@code LibertyRecomp/} - one cvar per line,
 *       passed to SDL_main, so settings change without a rebuild.</li>
 *   <li>{@code driver.txt} beside it - "system" to bypass the bundled Turnip
 *       Vulkan driver.</li>
 * </ul>
 */
public class LibertyActivity extends SDLActivity {

    private static final String TAG = "LibertyRecomp";
    private static final String RESOURCES = "Resources";
    private static final String RESOURCES_STAMP = ".stamp";

    private String[] mArguments = new String[0];
    private String mDriverMode = DriverBridge.TURNIP;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        prepareEnvironment();
        super.onCreate(savedInstanceState);
        // A controller-driven game sends no touch events for minutes at a time.
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
    }

    /** Picks the Vulkan driver before SDL loads libmain.so; see DriverBridge. */
    @Override
    public void loadLibraries() {
        DriverBridge.initialize(this, mDriverMode);
        super.loadLibraries();
    }

    @Override
    protected String[] getArguments() {
        return mArguments;
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        if (hasFocus) {
            hideSystemBars();
        }
    }

    private void prepareEnvironment() {
        File external = getExternalFilesDir(null);
        File dataRoot = external != null ? external : getFilesDir();
        File resources = new File(getFilesDir(), RESOURCES);
        try {
            syncResources(resources);
        } catch (IOException e) {
            Log.e(TAG, "copying bundled resources failed", e);
        }
        setenv("XDG_DATA_HOME", dataRoot.getAbsolutePath());
        setenv("HOME", dataRoot.getAbsolutePath());
        setenv("REX_RESOURCES_DIR", resources.getAbsolutePath());
        mArguments = readArguments(new File(dataRoot, "args.txt"));
        String driver = readFirstLine(new File(dataRoot, "driver.txt"));
        if (driver != null && driver.trim().equals(DriverBridge.SYSTEM)) {
            mDriverMode = DriverBridge.SYSTEM;
        }
        Log.i(TAG, "data=" + dataRoot + " resources=" + resources
                + " args=" + mArguments.length + " driver=" + mDriverMode);
    }

    private static void setenv(String name, String value) {
        try {
            Os.setenv(name, value, true);
        } catch (ErrnoException e) {
            Log.e(TAG, "setenv " + name + " failed", e);
        }
    }

    /** Re-copies the bundled resources whenever the installed APK changes. */
    private void syncResources(File target) throws IOException {
        String stamp;
        try {
            PackageInfo info = getPackageManager().getPackageInfo(getPackageName(), 0);
            stamp = info.versionCode + ":" + info.lastUpdateTime;
        } catch (Exception e) {
            stamp = "unknown";
        }
        File stampFile = new File(target, RESOURCES_STAMP);
        if (stamp.equals(readFirstLine(stampFile))) {
            return;
        }
        deleteRecursively(target);
        copyAssetTree(getAssets(), RESOURCES, target);
        try (OutputStream out = new FileOutputStream(stampFile)) {
            out.write(stamp.getBytes(StandardCharsets.UTF_8));
        }
        Log.i(TAG, "bundled resources copied to " + target);
    }

    private static void copyAssetTree(AssetManager assets, String path, File target)
            throws IOException {
        String[] children = assets.list(path);
        if (children == null || children.length == 0) {
            File parent = target.getParentFile();
            if (parent != null && !parent.isDirectory() && !parent.mkdirs()) {
                throw new IOException("cannot create " + parent);
            }
            try (InputStream in = assets.open(path);
                 OutputStream out = new FileOutputStream(target)) {
                byte[] buffer = new byte[64 * 1024];
                int read;
                while ((read = in.read(buffer)) > 0) {
                    out.write(buffer, 0, read);
                }
            }
            return;
        }
        if (!target.isDirectory() && !target.mkdirs()) {
            throw new IOException("cannot create " + target);
        }
        for (String child : children) {
            copyAssetTree(assets, path + "/" + child, new File(target, child));
        }
    }

    private static void deleteRecursively(File file) {
        File[] children = file.listFiles();
        if (children != null) {
            for (File child : children) {
                deleteRecursively(child);
            }
        }
        if (file.exists() && !file.delete()) {
            Log.w(TAG, "cannot delete " + file);
        }
    }

    private static String readFirstLine(File file) {
        if (!file.isFile()) {
            return null;
        }
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(
                new FileInputStream(file), StandardCharsets.UTF_8))) {
            return reader.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    /** One argument per line; blank lines and lines starting with '#' are skipped. */
    private static String[] readArguments(File file) {
        List<String> arguments = new ArrayList<>();
        if (file.isFile()) {
            try (BufferedReader reader = new BufferedReader(new InputStreamReader(
                    new FileInputStream(file), StandardCharsets.UTF_8))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    line = line.trim();
                    if (!line.isEmpty() && !line.startsWith("#")) {
                        arguments.add(line);
                    }
                }
            } catch (IOException e) {
                Log.w(TAG, "cannot read " + file, e);
            }
        }
        return arguments.toArray(new String[0]);
    }

    @SuppressWarnings("deprecation")
    private void hideSystemBars() {
        getWindow().getDecorView().setSystemUiVisibility(
                View.SYSTEM_UI_FLAG_LAYOUT_STABLE
                        | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
                        | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
                        | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                        | View.SYSTEM_UI_FLAG_FULLSCREEN
                        | View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY);
    }
}
