#!/bin/bash
# Configure (once), build and stage the native side for the APK:
#   jniLibs/arm64-v8a  libmain.so, librexruntime*.so, librexgpu-*.so,
#                      libSDL3*.so, libc++_shared.so
#   assets/Resources   fonts, button prompts and the RPF key
#
# usage: build_native.sh [jobs]      (default: number of CPUs - 2)
set -euo pipefail
. "$(dirname "$0")/env.sh"
JOBS="${1:-$(( $(nproc) > 3 ? $(nproc) - 2 : 1 ))}"

[ -d "$ANDROID_NDK" ] || { echo "no NDK at $ANDROID_NDK"; exit 1; }

python "$APP_DIR/scripts/materialize_symlinks.py"
"$APP_DIR/scripts/setup_host_tools.sh"

if [ ! -f "$BUILD_DIR/CMakeCache.txt" ]; then
  echo "== configuring $BUILD_TYPE in $BUILD_DIR"
  cmake -S "$REPO" -B "$BUILD_DIR" -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE="$REPO/toolchains/android.cmake" \
    -DANDROID_NDK="$ANDROID_NDK" \
    -DANDROID_ABI=arm64-v8a \
    -DANDROID_PLATFORM=android-28 \
    -DANDROID_STL=c++_shared \
    -DLIBERTY_RECOMP_TARGET_PLATFORM=android \
    -DLIBERTY_RECOMP_ANDROID_RUNTIME_ASSETS=ON \
    -DCMAKE_BUILD_TYPE="$BUILD_TYPE" \
    -DCMAKE_POLICY_VERSION_MINIMUM=3.5 \
    -DREXGLUE_ENABLE_TRACY=OFF \
    -DGTA4_NATIVE_SPIRV_VAL="$(cygpath -m "$ANDROID_NDK/shader-tools/windows-x86_64/spirv-val.exe")" \
    -DGTA4_NATIVE_GLSLANG_VALIDATOR="$(cygpath -m "$REPO/out/host-tools/glslang/bin/glslangValidator.exe")" \
    -DGTA4_NATIVE_DXC_LIBRARY_PATH="$(cygpath -m "$REPO/out/host-tools/dxc/bin/x64")"
fi

echo "== building with $JOBS jobs"
cmake --build "$BUILD_DIR" --target LibertyRecomp -- -j"$JOBS"

echo "== staging libraries"
rm -rf "$JNILIBS"
mkdir -p "$JNILIBS"
for so in "$BUILD_DIR"/glue/gta4-recomp/libmain.so "$REX_OUT_DIR"/librexruntime.so \
          "$REX_OUT_DIR"/librexgpu-*.so "$REX_OUT_DIR"/libSDL3.so; do
  [ -f "$so" ] || continue
  # Packaged unstripped by default so ndk-stack and simpleperf can resolve
  # frames. STRIP=1 makes a smaller APK.
  if [ "${STRIP:-0}" = "1" ]; then
    "$NDK_BIN/llvm-strip" --strip-unneeded -o "$JNILIBS/$(basename "$so")" "$so"
  else
    cp "$so" "$JNILIBS/"
  fi
done
cp "$NDK_SYSROOT_LIB/libc++_shared.so" "$JNILIBS/"

echo "== checks"
"$NDK_BIN/llvm-nm" -D --defined-only "$JNILIBS/libmain.so" | grep -E ' SDL_main$' >/dev/null || {
  echo "!! SDL_main is not exported from libmain.so"; exit 1; }
# Every DT_NEEDED entry must be either staged here or a system library.
for so in "$JNILIBS"/*.so; do
  for need in $("$NDK_BIN/llvm-readelf" -d "$so" | sed -n 's/.*Shared library: \[\(.*\)\]/\1/p'); do
    case "$need" in
      libc.so|libm.so|libdl.so|liblog.so|libandroid.so|libvulkan.so|libEGL.so|libGLESv2.so|libGLESv3.so|libOpenSLES.so|libaaudio.so|libz.so|libmediandk.so|libnativewindow.so|libjnigraphics.so) ;;
      *) [ -f "$JNILIBS/$need" ] || { echo "!! $(basename "$so") needs $need, which is not staged"; exit 1; } ;;
    esac
  done
done
ls -la "$JNILIBS"

echo "== staging resources"
RES="$ASSETS/Resources"
rm -rf "$RES"
mkdir -p "$RES/button_prompts"
cp -r "$REPO/LibertyRecompLib/font_atlases" "$RES/"
cp -r "$REPO/LibertyRecompLib/private/button_prompts/." "$RES/button_prompts/"
[ -f "$REPO/LibertyRecompLib/aes_key.bin" ] && cp "$REPO/LibertyRecompLib/aes_key.bin" "$RES/"
du -sh "$RES"
echo "== done"
