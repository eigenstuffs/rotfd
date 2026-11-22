#ifndef GAME_PLATFORM_VIDEO_RESUME_INTERNAL_H
#define GAME_PLATFORM_VIDEO_RESUME_INTERNAL_H
#include "Game/platform_disc_wait_internal.h"
struct PlatformVideoTransition {
    signed char paused;
    char unknown01[0x5B];
    signed char enabled;
    signed char black;
};
extern "C" {
    extern void* lbl_80378120;
    extern u32 lbl_803780F0[2];
    void VIConfigure(void*);
    void VIFlush();
    void VIWaitForRetrace();
    void VISetBlack(int);
    int OSResumeThread(void*);
}
typedef char CheckPlatformVideoTransition[sizeof(PlatformVideoTransition)==0x5E?1:-1];
#endif
