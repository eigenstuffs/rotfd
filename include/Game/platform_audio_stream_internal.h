#ifndef GAME_PLATFORM_AUDIO_STREAM_INTERNAL_H
#define GAME_PLATFORM_AUDIO_STREAM_INTERNAL_H
#include "Game/platform_audio_internal.h"
struct AudioStreamRecord {char unknown00[0x54];u32 flags;char unknown58[4];};
struct AudioStreamVoice {AXVPB*voice[2];char unknown08[0x34];};
struct AudioStreamQueue {void*head,*tail;};
struct AudioStreamMutex {AudioStreamQueue queue;void*thread;long count;AudioStreamMutex*next,*prev;};
struct AudioStreamingState {
 AudioStreamRecord records[6];AudioStreamVoice voices[6];
 char unknown390[0x2C0];AudioStreamQueue queue;
 char unknown658[0x43D0];char fileInfo[0x3C];u32 unknown4A64;
 signed char opened;char unknown4A69[3];float musicLevel,effectsLevel;char names[6][16];
};
struct AudioStreamRegistry {char unknown00[0x10C];AudioStreamRegistry*next;};
extern "C" {
extern AudioStreamMutex lbl_8035E958;extern AudioStreamRegistry*lbl_803780D0;
void OSWakeupThread(void*);void OSLockMutex(void*);void OSUnlockMutex(void*);
void MIXSetInput(AXVPB*,int);
int fn_801F4520(const char*,const char*);int strncmp(const char*,const char*,u32);
void*memset(void*,int,u32);int DVDClose(void*);
void fn_8028A4F0(void*,int);
}
typedef char CheckAudioStreamMutex[sizeof(AudioStreamMutex)==24?1:-1];
typedef char CheckAudioStreamRecord[sizeof(AudioStreamRecord)==92?1:-1];
typedef char CheckAudioStreamVoice[sizeof(AudioStreamVoice)==60?1:-1];
typedef char CheckAudioStreamingState[sizeof(AudioStreamingState)==0x4AD4?1:-1];
#endif
