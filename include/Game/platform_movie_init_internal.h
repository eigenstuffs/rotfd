#ifndef GAME_PLATFORM_MOVIE_INIT_INTERNAL_H
#define GAME_PLATFORM_MOVIE_INIT_INTERNAL_H
#include "Game/platform_video_resume_internal.h"
struct MoviePlatformInit {
    char unknown00[0x48];
    u32 word48;
    char unknown4C[4];
    void* allocation;
    char unknown54[8];
    signed char enabled;
    signed char black;
};
struct MovieVideoModePrefix {
    u32 format;
    unsigned short width;
    unsigned short unknown06;
    unsigned short height;
};
extern "C" {
    extern MovieVideoModePrefix GXNtsc480Int;
    extern u32 lbl_80378104;
    extern char lbl_801EF5C8[];
    extern const char lbl_802AF7A0[], lbl_802AF7B0[];
    signed char fn_801C9AC0(void*);
    u32 VIGetTvFormat();
    void* fn_801EFA1C(void*,u32,const char*,const char*,int,u32);
}
typedef char CheckMoviePlatformInit[sizeof(MoviePlatformInit)==0x60?1:-1];
#endif
