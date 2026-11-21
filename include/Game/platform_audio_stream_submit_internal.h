#ifndef GAME_PLATFORM_AUDIO_STREAM_SUBMIT_INTERNAL_H
#define GAME_PLATFORM_AUDIO_STREAM_SUBMIT_INTERNAL_H
#include "Game/platform_audio_stream_internal.h"
struct StreamSubmitRegistry {char path[128],name[128];int kind;signed char loop;char unknown105[3];int cookie;StreamSubmitRegistry*next;};
struct StreamSubmitContext {char unknown00[0x18];OwnerHandle owner;};
struct StreamSubmitOwner {char unknown00[0x48];OwnerHandle target;};
struct StreamSubmitTarget {char unknown00[0x134];void(*callback)(void*,void*);void*cookie;};
struct StreamSubmitGlobals {char unknown00[0x124];StreamSubmitContext*context;};
extern "C" {
extern const char lbl_802AF56C[],lbl_802AF57C[];
void fn_8028AE40(void*,void*);void*fn_801EFA1C(void*,u32,const char*,const char*,int,int);
char*strncpy(char*,const char*,u32);
int fn_8028A31C(AudioStreamingState*,const char*,int,int,int);
}
#endif
