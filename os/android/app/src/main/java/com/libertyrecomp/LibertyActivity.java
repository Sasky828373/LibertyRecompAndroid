package com.libertyrecomp;

import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.res.AssetManager;
import android.os.Build;
import android.os.Bundle;
import android.system.ErrnoException;
import android.system.Os;
import android.util.Log;
import android.view.View;
import android.view.WindowManager;

import org.libsdl.app.SDLActivity;
import org.libsdl.app.SDLSurface;

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
import java.util.Arrays;
import java.util.List;
import java.util.Locale;

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
    private static final String DEFAULT_ARGS = "default_args.txt";

    private String[] mArguments = new String[0];
    /** "--android_surface=WxH" in args.txt: fixed swapchain size, scaled to the panel by the display hardware. */
    private static final String SURFACE_ARGUMENT = "--android_surface=";
    private int mSurfaceWidth;
    private int mSurfaceHeight;
    private String mDriverMode = DriverBridge.TURNIP;
    /** driver.txt as found, for the launch report. */
    private String mDriverText;
    private File mDataRoot;
    private static final String LAUNCH_REPORT = "last_launch.txt";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        prepareEnvironment();
        super.onCreate(savedInstanceState);
        // A controller-driven game sends no touch events for minutes at a time.
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
    }

    /**
     * Picks the Vulkan driver before SDL loads libmain.so; see DriverBridge.
     * When no driver can run the game, the error thrown here is shown by
     * SDLActivity in a dialog instead of the game closing without a word.
     */
    @Override
    public void loadLibraries() {
        String status = DriverBridge.initialize(this, mDriverMode);
        String reason = DriverBridge.unusableReason(status);
        writeLaunchReport(status, reason);
        if (reason != null) {
            throw new UnsatisfiedLinkError(reason
                    + "\n\nSupported GPUs: Qualcomm Adreno 6xx and 7xx."
                    + "\nA report was saved to Android/data/" + getPackageName()
                    + "/files/" + LAUNCH_REPORT + ".");
        }
        super.loadLibraries();
    }

    /**
     * Device, GPU and driver facts of this launch in the data folder, so a
     * player without adb can attach them to a bug report.
     */
    @SuppressWarnings("deprecation")
    private void writeLaunchReport(String driverStatus, String problem) {
        if (mDataRoot == null) return;
        StringBuilder report = new StringBuilder();
        String version = "?";
        try {
            PackageInfo info = getPackageManager().getPackageInfo(getPackageName(), 0);
            version = info.versionName + " (" + info.versionCode + ")";
        } catch (Exception ignored) {
        }
        report.append("Liberty Recompiled for Android ").append(version).append('\n');
        report.append("time: ").append(new java.util.Date()).append('\n');
        report.append("device: ").append(Build.MANUFACTURER).append(' ').append(Build.MODEL)
                .append(" (").append(Build.DEVICE).append(", board ").append(Build.BOARD)
                .append(", hardware ").append(Build.HARDWARE).append(")\n");
        if (Build.VERSION.SDK_INT >= 31) {
            report.append("soc: ").append(Build.SOC_MANUFACTURER).append(' ')
                    .append(Build.SOC_MODEL).append('\n');
        }
        report.append("android: ").append(Build.VERSION.RELEASE).append(" (API ")
                .append(Build.VERSION.SDK_INT).append(")\n");
        report.append("abis: ").append(String.join(", ", Build.SUPPORTED_ABIS)).append('\n');
        try {
            report.append("page size: ")
                    .append(Os.sysconf(android.system.OsConstants._SC_PAGESIZE)).append('\n');
        } catch (Exception ignored) {
        }
        String kgsl = readFirstLine(new File("/sys/class/kgsl/kgsl-3d0/gpu_model"));
        report.append("kgsl gpu: ").append(kgsl != null ? kgsl : "(not readable or not Adreno)")
                .append('\n');
        report.append("driver.txt: ")
                .append(mDriverText == null ? "(none)" : "\"" + mDriverText + "\"")
                .append(" -> ").append(mDriverMode).append('\n');
        report.append("driver status: ").append(driverStatus).append('\n');
        report.append("result: ").append(problem == null ? "driver usable, starting the game"
                : "cannot start: " + problem.replace('\n', ' ')).append('\n');
        try (OutputStream out = new FileOutputStream(new File(mDataRoot, LAUNCH_REPORT))) {
            out.write(report.toString().getBytes(StandardCharsets.UTF_8));
        } catch (IOException e) {
            Log.w(TAG, "writing the launch report failed", e);
        }
        Log.i(TAG, "launch report:\n" + report);
    }

    @Override
    protected SDLSurface createSDLSurface(Context context) {
        SDLSurface surface = super.createSDLSurface(context);
        if (mSurfaceWidth > 0 && mSurfaceHeight > 0) {
            surface.getHolder().setFixedSize(mSurfaceWidth, mSurfaceHeight);
            Log.i(TAG, "fixed surface " + mSurfaceWidth + "x" + mSurfaceHeight);
        }
        return surface;
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
        mDataRoot = dataRoot;
        File resources = new File(getFilesDir(), RESOURCES);
        try {
            syncResources(resources);
        } catch (IOException e) {
            Log.e(TAG, "copying bundled resources failed", e);
        }
        setenv("XDG_DATA_HOME", dataRoot.getAbsolutePath());
        setenv("HOME", dataRoot.getAbsolutePath());
        setenv("REX_RESOURCES_DIR", resources.getAbsolutePath());
        // Turnip's GMEM (tiled) mode loses ~15% on this renderer's many small
        // passes and resolves; direct system-memory rendering is faster on the
        // Adreno 650. env.txt may override it.
        setenv("TU_DEBUG", "sysmem");
        applyEnvironmentFile(new File(dataRoot, "env.txt"));
        File argsFile = new File(dataRoot, "args.txt");
        if (!argsFile.isFile()) {
            // First launch: start from the tuned handheld profile bundled in
            // the APK; the copy stays editable next to LibertyRecomp/.
            try {
                copyAssetTree(getAssets(), DEFAULT_ARGS, argsFile);
            } catch (IOException e) {
                Log.e(TAG, "writing default args failed", e);
            }
        }
        List<String> arguments = new ArrayList<>(Arrays.asList(readArguments(argsFile)));
        addInstallSources(new File(dataRoot, "install"), arguments);
        for (int i = arguments.size() - 1; i >= 0; --i) {
            String argument = arguments.get(i);
            if (!argument.startsWith(SURFACE_ARGUMENT)) continue;
            arguments.remove(i);  // Java-side setting; the runtime does not know it.
            String[] size = argument.substring(SURFACE_ARGUMENT.length()).split("x");
            try {
                if (size.length == 2) {
                    mSurfaceWidth = Integer.parseInt(size[0].trim());
                    mSurfaceHeight = Integer.parseInt(size[1].trim());
                }
            } catch (NumberFormatException e) {
                Log.w(TAG, "bad " + argument);
            }
        }
        mArguments = arguments.toArray(new String[0]);
        String driver = readFirstLine(new File(dataRoot, "driver.txt"));
        mDriverText = driver;
        String lower = driver == null ? "" : driver.toLowerCase(Locale.ROOT);
        if (lower.startsWith(DriverBridge.CUSTOM_PREFIX)) {
            mDriverMode = DriverBridge.CUSTOM_PREFIX
                    + driver.substring(DriverBridge.CUSTOM_PREFIX.length()).trim();
        } else if (lower.equals(DriverBridge.SYSTEM)) {
            mDriverMode = DriverBridge.SYSTEM;
        } else if (!lower.isEmpty() && !lower.equals(DriverBridge.TURNIP)) {
            Log.w(TAG, "unknown driver.txt value \"" + driver + "\", using Turnip");
        }
        Log.i(TAG, "data=" + dataRoot + " resources=" + resources
                + " args=" + mArguments.length + " driver=" + mDriverMode);
    }

    /**
     * Optional NAME=value lines (e.g. Turnip's TU_DEBUG) exported before the
     * Vulkan driver loads; '#' starts a comment.
     */
    private static void applyEnvironmentFile(File file) {
        if (!file.isFile()) {
            return;
        }
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(
                new FileInputStream(file), StandardCharsets.UTF_8))) {
            String line;
            while ((line = reader.readLine()) != null) {
                line = cleanLine(line);
                int equals = line.indexOf('=');
                if (line.isEmpty() || line.startsWith("#") || equals <= 0) {
                    continue;
                }
                String name = line.substring(0, equals).trim();
                String value = line.substring(equals + 1).trim();
                setenv(name, value);
                Log.i(TAG, "env " + name + "=" + value);
            }
        } catch (IOException e) {
            Log.e(TAG, "reading " + file + " failed", e);
        }
    }

    /**
     * The SDL file picker returns content:// URIs the installer cannot read, so
     * sources are taken from files/install/ (writable over USB without any
     * storage permission): the first *.iso is the disc, any other file the
     * title update. Explicit --install_* lines in args.txt win.
     */
    private static void addInstallSources(File dir, List<String> arguments) {
        if (!dir.isDirectory() && !dir.mkdirs()) {
            return;
        }
        for (String argument : arguments) {
            if (argument.startsWith("--install_")) {
                return;
            }
        }
        File[] files = dir.listFiles();
        if (files == null) {
            return;
        }
        File disc = null;
        File update = null;
        for (File file : files) {
            if (!file.isFile() || file.getName().startsWith(".")) {
                continue;
            }
            if (file.getName().toLowerCase(java.util.Locale.ROOT).endsWith(".iso")) {
                if (disc == null) disc = file;
            } else if (update == null || file.length() > update.length()) {
                update = file;
            }
        }
        if (disc != null) {
            arguments.add("--install_game_source=" + disc.getAbsolutePath());
            Log.i(TAG, "install disc " + disc);
        }
        if (update != null) {
            arguments.add("--install_update_source=" + update.getAbsolutePath());
            Log.i(TAG, "install title update " + update);
        }
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
            String line = reader.readLine();
            return line == null ? null : cleanLine(line);
        } catch (IOException e) {
            return null;
        }
    }

    /**
     * Trims a line of a settings file, including the byte-order mark some
     * editors (Windows Notepad among them) put at the start of a file.
     */
    private static String cleanLine(String line) {
        return line.replace("\uFEFF", "").trim();
    }

    /** One argument per line; blank lines and lines starting with '#' are skipped. */
    private static String[] readArguments(File file) {
        List<String> arguments = new ArrayList<>();
        if (file.isFile()) {
            try (BufferedReader reader = new BufferedReader(new InputStreamReader(
                    new FileInputStream(file), StandardCharsets.UTF_8))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    line = cleanLine(line);
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
