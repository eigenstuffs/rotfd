#include "Game/platform_video_resume_internal.h"

extern "C" void fn_8028D4CC(PlatformVideoTransition* state)
{
    if (state->enabled) {
        if (state->paused) {
            VIConfigure(lbl_80378120);
            VIFlush();
            VIWaitForRetrace();
            lbl_803780F0[0] = 1;
            lbl_803780F0[1] = 1;
            VISetBlack(0);
            VIFlush();
            OSResumeThread(lbl_8036E9D0);
            state->paused = 0;
        }
    }
    if (state->black)
        VISetBlack(1);
}

extern "C" unsigned char fn_8028D560(PlatformVideoTransition* state)
{
    return state->enabled;
}
