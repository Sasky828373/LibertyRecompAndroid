# Android 120 FPS efficiency bundle

This branch changes the Android launch defaults and ships `os/android/android_args/120fps_efficiency.txt`.

## Included
- Requests a 120 Hz present limit with VSync.
- Explicitly keeps the existing high-value native command recycle/coalescing, lazy constant hashing, prepared binding, vertex-cache ordering, and related optimization switches on.
- Disables the 30-FPS-oriented dynamic distance controller for the 120 FPS quality-preserving profile. This can **increase** load versus adaptive detail under heavy scenes; it avoids silent visual reductions, not a speed gain.
- Leaves native 720p, FXAA, world density, shadows, and reflection range at the previous Android defaults.
- Leaves profiling scopes off for normal play.

## What this does NOT do
This is a consolidated profile of **existing** optimizations, not a new renderer rewrite. It does not establish lower CPU/GPU utilization or stable 120 FPS. It may draw more power than the old 30 FPS default. The default args file is only copied to app storage on first launch; an existing `args.txt` overrides it.

## Apply without deleting saves
1. Back up `Android/data/com.libertyrecomp/files/args.txt`.
2. Copy the contents of `os/android/android_args/120fps_efficiency.txt` into `args.txt` using a Shizuku-capable file manager or adb.
3. Stop and relaunch the game; compare with exactly the same camera, time of day and savegame.

## Profiling and next actual code changes
Use `os/android/scripts/fps.sh`, `cpu_frame.sh`, `gpu_counters.sh` on identical 120-FPS scenes. Measure p50/p95/p99 CPU frame times, GPU frame times, draw counts, render-pass/resolves, cache misses and total power. Only then modify the GPU command submission path (render-pass fusion, draw batching and descriptor recycling) one at a time, checking rendering correctness and driver stability. GPU utilization alone is not a performance metric.

The existing `gta4_fps_guard` and dynamic draw-distance control target 30 FPS in the current documented implementation. Rework them for a configurable 120-FPS budget before treating them as 120-FPS stabilizers.
