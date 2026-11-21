#ifndef GAME_PLATFORM_VIDEO_PAUSE_INTERNAL_H
#define GAME_PLATFORM_VIDEO_PAUSE_INTERNAL_H
#include "Game/platform_video_resume_internal.h"
extern "C" {
    extern u32* lbl_803780F8;
    extern u32 lbl_80378104;
    extern const char lbl_802AF6D8[];
    int OSSuspendThread(void*);
    void DCFlushRangeNoSync(void*,u32);
    void PPCSync();
    void VISetNextFrameBuffer(void*);
    void GXDrawDone();
}
#endif
