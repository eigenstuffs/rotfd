#include "Game/platform_audio_update_internal.h"
extern "C" u32 OSGetSoundMode();
extern "C" void OSSetSoundMode(u32);
extern "C" signed char fn_802876AC(PlatformAudioUpdateOwner*){return OSGetSoundMode()==1;}
extern "C" void fn_802876DC(PlatformAudioUpdateOwner*,int stereo){if(stereo)OSSetSoundMode(1);else OSSetSoundMode(0);}
extern "C" void fn_80287714(PlatformAudioUpdateOwner*){}
