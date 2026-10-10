# Diagnosing 120 FPS frame-time hitches (Android)

The 120 FPS frame budget is **8.333 ms**. Average FPS alone does not
measure the spikes: track P95/P99 frame times and >16.67 ms outliers during
the same in-game route, day/time and driver.

## Safe baseline

Use `os/android/android_args/120fps-stability.txt` as a **separate test profile**,
not a replacement for the default Snapdragon 865 profile. Back up the current
`args.txt` first. This retains the default resolution, world density and
shadows; it disables the dynamic draw distance while comparing frame times
because the original controller's miss budget was designed around 30 FPS.
Run with the screen actually at 120 Hz. Change one variable at a time.

Do not delete Vulkan/Mesa shader caches on every start: cold compilation
can cause new hitches. Run an identical driving route twice after driver or
APK changes, and compare the **second** run separately from cold-start results.

## Capture

1. Record the exact APK commit, GPU driver build, display refresh rate,
   graphics profile and phone temperature.
2. Collect presentation timing using `os/android/scripts/fps.sh` and CPU
   scheduling samples using `os/android/scripts/cpu_frame.sh`.
3. Check `logcat` for `LibertyDriver`, renderer stalls, swapchain recreation,
   I/O failures or thermal warnings at the timestamp of the hitch.
4. Repeat with `--gta4_native_max_queued_frames=2` versus `3`: two may improve
   latency but can reduce throughput; **do not assume** either is universally faster.
5. Compare Vulkan system vs compatible custom Turnip only when both launch
   successfully. Shader caches and drivers differ, so warm each independently.

## Interpreting a trace

- First traversal hitches but repeat smooth: suspect shader/pipeline creation
  or cold asset streaming; capture their durations before adding prewarm work.
- Repeated hitches at the same street/intersection: inspect synchronous RPF
  reads, decompression and streaming queues.
- Render/recorder thread blocked while CPU has headroom: inspect queue
  saturation, mutex contention, submission fences and allocation bursts.
- GPU busy continuously when frame time spikes: identify expensive passes;
  retain identical resolution/detail during investigation.
- Periodic 16.7/33 ms frames near 120 FPS: examine Android surface refresh,
  VSYNC pacing and acquire/present wait timestamps before tuning thread priorities.

## Performance changes that require measurement

Pipeline prewarm must avoid blocking the first interactive frame. Background
streaming and buffer pools need bounded memory and lifetime correctness.
Never remove safety fences, disable synchronization globally, or force CPU
affinity without a trace. A true fix needs CPU/GPU timing evidence on the
target Adreno device.
