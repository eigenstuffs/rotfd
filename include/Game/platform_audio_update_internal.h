#ifndef GAME_PLATFORM_AUDIO_UPDATE_INTERNAL_H
#define GAME_PLATFORM_AUDIO_UPDATE_INTERNAL_H
#include "Game/platform_audio_internal.h"
struct PlatformAudioUpdateOwner;
struct PlatformAudioTrack {OwnerHandle owner,first,second;u32 unknown0C;float timer;signed char running;char unknown15[7];};
struct PlatformAudioOwnerStorage {char unknown00[0x7C];};
struct PlatformAudioUpdateOwner : PlatformAudioOwnerStorage {
 virtual void slot08();virtual void slot0C();virtual void slot10();
 virtual void slot14();virtual void slot18();virtual void channelDone(int);
 PlatformAudioTrack tracks[32];char unknown400[8];u32 flags;u32 unknown40C;
 PlatformAudioChannel*channels;float field414,field418;u32 unknown41C;char secondary[4];
};

extern "C" {
extern const float lbl_8037B8A4,lbl_8037B8A8,lbl_8037B8AC,lbl_8037B8B0;
void fn_80286830(PlatformAudioUpdateOwner*,Activable_Z*,Activable_Z*,PlatformAudioChannel*);
signed char fn_8023B508(PlatformAudioUpdateOwner*,Activable_Z*,Activable_Z*);
void MIXSetPan(AXVPB*,u32);void MIXSetInput(AXVPB*,int);
float fn_80284DB4(float);
void fn_8028970C(void*);
}
typedef char CheckAudioTrack[sizeof(PlatformAudioTrack)==28?1:-1];
#endif
