#ifndef GAME_PLATFORM_VIDEO_CLEANUP_INTERNAL_H
#define GAME_PLATFORM_VIDEO_CLEANUP_INTERNAL_H
#include "Game/platform_video_resume_internal.h"
struct VideoTransitionPrefix {
    signed char paused;
    char unknown01[7];
};
struct VideoTransitionCleanup : VideoTransitionPrefix {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    char unknown0C[0x44];
    void* allocation;
    char unknown54[8];
    signed char enabled;
    signed char black;
};
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*, void*);
    void fn_801C9ABC(void*);
}
typedef char CheckVideoTransitionCleanup[sizeof(VideoTransitionCleanup)==0x60?1:-1];
#endif
