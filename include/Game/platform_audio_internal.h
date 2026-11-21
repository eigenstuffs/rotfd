#ifndef GAME_PLATFORM_AUDIO_INTERNAL_H
#define GAME_PLATFORM_AUDIO_INTERNAL_H
#include "objects_owner_internal.h"
extern "C" {
#include "ax/ax_abi.h"
}
struct PlatformAudioChannel {
 float field00,field04,field08,field0C;
 u32 flags;float field14,field18;int field1C;u32 unknown20;AXVPB*voice;
};
struct PlatformAudioOwner {
 char unknown00[0x410];PlatformAudioChannel*channels;float field414,field418;
 u32 unknown41C;char secondary[4];
};
extern "C" {
extern const float lbl_8037B898,lbl_8037B89C,lbl_8037B8A0;
void fn_8023B720(PlatformAudioOwner*,int);
void fn_80285730(void*);
signed char fn_8028A6C4(void*,int);
}
typedef char CheckAudioChannel[sizeof(PlatformAudioChannel)==40?1:-1];
#endif
