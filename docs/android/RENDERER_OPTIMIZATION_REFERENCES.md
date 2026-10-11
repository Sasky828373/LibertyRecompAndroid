# Source-guided native Android renderer optimization

The goal is lower CPU and GPU time **at the same 120 FPS and visual fidelity**, not merely lower GPU utilization at a reduced frame rate.

## External implementation references

1. [Khronos Vulkan Samples: Descriptor management](https://github.com/KhronosGroup/Vulkan-Samples/blob/main/samples/performance/descriptor_management/README.adoc) — cache descriptor sets, avoid repeated pool resets and updates on the hot path.
2. [Dolphin ShaderCache.cpp](https://github.com/dolphin-emu/dolphin/blob/master/Source/Core/VideoCommon/ShaderCache.cpp) — persistent shader/Pipeline UID caching and background compilation to reduce compilation spikes (not necessarily average GPU utilization).
3. [Mesa Freedreno/Turnip](https://docs.mesa3d.org/drivers/freedreno.html) — Adreno has separate GMEM tiled vs system-memory rendering paths, with tradeoffs per pass.
4. [Mesa Turnip environment](https://docs.mesa3d.org/envvars.html) — `TU_DEBUG=sysmem` and `TU_DEBUG=gmem` are **test overrides**, not universal optimizations.
5. [Dolphin performance guide](https://enj.dolphin-emu.org/docs/guides/performance-guide/) — shader compilation stutters and cache warmup.

## What has actually changed in this branch

- Sharded the GTA IV cached-command-list table with parallel readers.
- Reduced free-range traversal in the native buffer arena; first exact fit wins since blocks are ordered.
- Changed the descriptor epoch pending-batch guard from linear search to constant-time counter.
- Added an explicit 120 FPS profile preserving the previous 720p-native scene settings.

## What needs validated GPU-specific work

- Instrument render pass count, images resolved, bytes read/written and draw count at the heaviest location (day and night).
- Merge passes **only** where load/store, hazards, clears and texture read dependencies permit. Incorrect merges cause silent corruption.
- Cache Vulkan pipelines after hashing full shader state and render target compatibility. Reuse immutable descriptor sets only while all bound resource generations remain valid and no referenced frame is in flight.
- Driver choice: measure system Adreno versus verified device-compatible Turnip, and compare default, GMEM and SYSMEM. Never force one mode for every Adreno generation.
- Benchmark original and optimized APKs with **identical** app data, camera, weather, render resolution, graphics settings and driver. Record CPU/GPU frame times p50, p95, p99, thermal power and real presented FPS. 120 FPS = 8.333 ms per presented frame.

No performance gain, APK build success, or 120 FPS guarantee is implied by these source edits without tests. Keep the PR as draft until CI and on-device validation succeed.
