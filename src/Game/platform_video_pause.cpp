#include "Game/platform_video_pause_internal.h"

static inline void fill(u32* first, u32* last, u32 value)
{
    for (; first < last; first++)
        *first = value;
}

extern "C" void fn_8028D568(PlatformVideoTransition* state)
{
    const char* strings = lbl_802AF6D8;
    if (state->enabled) {
        if (!state->paused) {
            state->paused = 1;
            fn_801FA014(lbl_801E9D24.logger, strings + 0x184);
            OSSuspendThread(lbl_8036E9D0);
            fn_801FA014(lbl_801E9D24.logger, strings + 0x1A0);
            for (int i = 0; i < 2; i++) {
                fill(lbl_803780F8,
                     (u32*)((char*)lbl_803780F8 + lbl_80378104),
                     (u32)0x00800080);
                DCFlushRangeNoSync(lbl_803780F8, lbl_80378104);
                PPCSync();
                VISetNextFrameBuffer(lbl_803780F8);
                VIFlush();
                VIWaitForRetrace();
            }
            fn_801FA014(lbl_801E9D24.logger, strings + 0x1BC);
            VIFlush();
            GXDrawDone();
            VIWaitForRetrace();
            fn_801FA014(lbl_801E9D24.logger, strings + 0x1D8);
            VIConfigure((char*)lbl_801E9D24.game + 0x294);
            VIFlush();
            VIWaitForRetrace();
            fn_801FA014(lbl_801E9D24.logger, strings + 0x1F4);
        }
    }
    if (state->black)
        VISetBlack(0);
}
