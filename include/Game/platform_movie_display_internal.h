#ifndef GAME_PLATFORM_MOVIE_DISPLAY_INTERNAL_H
#define GAME_PLATFORM_MOVIE_DISPLAY_INTERNAL_H
#include "Game/platform_movie_init_internal.h"
#include "Game/platform_video_pause_internal.h"
struct MovieDecodeMode {unsigned short unknown00;unsigned short format;};
struct MovieFrameCallbackStorage {char unknown00[0x1C];};
struct MovieFrameCallback:MovieFrameCallbackStorage {
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void tick(float);
};
struct MovieDisplayGlobals {char unknown00[0x154];MovieFrameCallback*callback;char unknown158[4];MoviePlatformInit*platform;};
extern "C" {
 extern MovieDecodeMode lbl_8037814C;
 extern void* lbl_80378154;
 extern u32* lbl_80378108;extern u32* lbl_8037810C;extern u32* lbl_80378110;extern u32* lbl_80378114;
 extern u32 lbl_80378118,lbl_8037811C,lbl_80378100;
 extern int lbl_803780FC,lbl_803780E8,lbl_80378158;
 extern u32*lbl_80378128[2];
 extern float lbl_8037B91C;
 int OSWaitSemaphore(void*);int OSSignalSemaphore(void*);
 void fn_802954D0(void*,void*,void*,void*);
 void fn_802959E0(void*,void*,void*,void*);
 void fn_80295A04(void*,void*,void*,void*,void*);
 void fn_8028DB38(void*,void*,u32,u32);
 void GXSetColorUpdate(int);
}
typedef char CheckMovieDecodeMode[sizeof(MovieDecodeMode)==4?1:-1];
typedef char CheckMovieFrameCallback[sizeof(MovieFrameCallback)==0x20?1:-1];
typedef char CheckMovieDisplayGlobals[sizeof(MovieDisplayGlobals)==0x160?1:-1];
#endif
