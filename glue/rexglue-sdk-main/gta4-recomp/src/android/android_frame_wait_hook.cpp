// sub_82A46D70(device r3, out r4) writes {0, submitted frame, submitted -
// completed} for the device. Its only caller, sub_828BF420, polls it in a
// loop without sleeping while two frames are pending, i.e. while the title
// waits for the renderer to submit a frame: a busy-wait that held a big core
// at ~7% of the main game thread's samples. Sleep briefly when the title is
// about to spin; the game's own loop still decides when to stop waiting.
#include <time.h>

#include <rex/cvar.h>

#include "gta4_init.h"

// Off by default: it gained nothing measurable, and the game-code crash in
// sub_8296E480 (stale object pointer) first appeared in builds that had it;
// changing the main thread's timing can expose game-side races.
REXCVAR_DEFINE_BOOL(gta4_frame_wait_sleep, false, "GTA IV/Performance",
                    "Sleep instead of spinning while the title waits for a frame slot");

extern "C" void sub_82A46D70(PPCContext& ctx, uint8_t* base) {
  const uint32_t out = ctx.r4.u32;
  __imp__sub_82A46D70(ctx, base);
  const uint32_t pending = REX_LOAD_U32(out + 8);
  if (pending >= 2 && pending < 0x80000000u && REXCVAR_GET(gta4_frame_wait_sleep)) {
    const timespec delay{0, 250 * 1000};
    nanosleep(&delay, nullptr);
  }
}
