// sub_8296E480(owner r3, out r4) copies the world matrix of the object at
// owner+56 into out, following object->[4]->[12] to a type check and a
// skeleton query; with no object it writes an identity matrix instead. The
// title frees such objects on another thread while this one still holds the
// owner, a race the console's timing hid: the faster renderer exposes it as
// a crash on an unmapped page inside this function. When the object's
// pointer chain no longer leads to mapped memory, take the title's own
// no-object path rather than fault.
#include <android/log.h>

#include <atomic>
#include <cstdint>

#include <rex/cvar.h>
#include <rex/runtime.h>

#include "gta4_init.h"

REXCVAR_DEFINE_BOOL(gta4_stale_object_guard, true, "GTA IV/Stability",
                    "Treat an object whose pointers lead to unmapped memory as absent in "
                    "sub_8296E480 instead of crashing");

namespace {

std::atomic<uint64_t> g_stale_objects{0};

// Recently confirmed readable 4 KB pages, valid while their heap's access
// epoch is unchanged (it reads 0 during a mutation and moves after it).
struct ReadablePage {
  const void* heap = nullptr;
  uint64_t epoch = 0;
  uint32_t page = UINT32_MAX;
};
thread_local ReadablePage t_readable_pages[16];
thread_local uint32_t t_readable_cursor = 0;

bool PageReadable(rex::memory::Memory* memory, uint32_t address) {
  auto* heap = memory->LookupHeap(address);
  if (!heap) return false;
  const uint64_t epoch = heap->access_epoch();
  const uint32_t page = address >> 12;
  for (const ReadablePage& cached : t_readable_pages) {
    if (cached.page == page && cached.heap == heap && cached.epoch == epoch && epoch) return true;
  }
  const uint32_t first = page << 12;
  using rex::memory::PageAccess;
  const auto access = heap->QueryRangeAccess(first, first + 0xFFF);
  const bool readable = access == PageAccess::kReadOnly || access == PageAccess::kReadWrite ||
                        access == PageAccess::kExecuteReadOnly ||
                        access == PageAccess::kExecuteReadWrite;
  if (readable && epoch) {
    t_readable_pages[t_readable_cursor++ % 16] = {heap, epoch, page};
  }
  return readable;
}

bool Readable(uint32_t address, uint32_t bytes) {
  if (!address || !bytes || uint64_t(address) + bytes > uint64_t(UINT32_MAX) + 1) return false;
  auto* runtime = rex::Runtime::instance();
  auto* memory = runtime ? runtime->memory() : nullptr;
  if (!memory) return false;
  const uint32_t end = uint32_t(uint64_t(address) + bytes - 1);
  if (!PageReadable(memory, address)) return false;
  return (end >> 12) == (address >> 12) || PageReadable(memory, end);
}

}  // namespace

extern "C" void sub_8296E480(PPCContext& ctx, uint8_t* base) {
  if (REXCVAR_GET(gta4_stale_object_guard)) {
    const uint32_t owner = ctx.r3.u32;
    const uint32_t out = ctx.r4.u32;
    bool valid = Readable(owner + 56, 4) && Readable(owner + 112, 4) && Readable(out, 64);
    const uint32_t object = valid ? REX_LOAD_U32(owner + 56) : 0;
    if (valid && object) {
      // Matrix at +16..+79 and the link at +4; then link+12 and its type byte.
      valid = Readable(object, 80);
      const uint32_t link = valid ? REX_LOAD_U32(object + 4) : 0;
      valid = valid && Readable(link + 12, 4);
      const uint32_t typed = valid ? REX_LOAD_U32(link + 12) : 0;
      valid = valid && Readable(typed + 4, 1);
    }
    if (!valid) {
      const uint64_t count = g_stale_objects.fetch_add(1, std::memory_order_relaxed) + 1;
      if (count <= 8 || !(count % 1024)) {
        __android_log_print(ANDROID_LOG_WARN, "LibertyRecomp",
                            "stale-object-guard: #%llu owner=%08X object=%08X out=%08X",
                            static_cast<unsigned long long>(count), owner, object, out);
      }
      if (Readable(out, 64)) {
        // The title's no-object path: identity rotation, zero translation,
        // with its 1.0/0.0 constants read from the same addresses.
        const uint32_t one = REX_LOAD_U32(0x81000000u + 3400);
        const uint32_t zero = REX_LOAD_U32(0x81000000u + 2612);
        const uint32_t layout[11][2] = {{0, one},  {4, zero},  {8, zero},  {16, zero},
                                        {20, one}, {24, zero}, {32, zero}, {36, zero},
                                        {40, one}, {48, 0},    {52, 0}};
        for (const auto& [offset, bits] : layout) REX_STORE_U32(out + offset, bits);
        REX_STORE_U32(out + 56, 0);
        REX_STORE_U32(out + 60, 0);
      }
      return;
    }
  }
  __imp__sub_8296E480(ctx, base);
}
