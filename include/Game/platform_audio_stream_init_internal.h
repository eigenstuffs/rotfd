#ifndef GAME_PLATFORM_AUDIO_STREAM_INIT_INTERNAL_H
#define GAME_PLATFORM_AUDIO_STREAM_INIT_INTERNAL_H
#include "Game/platform_audio_stream_release_internal.h"
struct StreamInitMusic {
 AXVPB*voice[2];u32 unknown08;void*unknown0C;u32 unknown10,unknown14,unknown18,unknown1C;
};
struct StreamInitQueue {void*head,*tail;};
struct StreamInitState {
 StreamReleaseRecord records[6];StreamReleaseVoice voices[4];StreamInitMusic music;
 char thread[0x318];StreamInitQueue queue;char unknown658[0x18];char*stack;
 char unknown674[0x390];u32 unknownA04,unknownA08;void*headA0C,*tailA10;
 u32 countA14;void*currentA18,*unknownA1C;u32 unknownA20,unknownA24;
 char unknownA28[0x4000];char fileInfo[0x3C];u32 unknown4A64;
 signed char opened;char unknown4A69[3];float musicLevel,effectsLevel;
 char names[6][16];void*allocation4AD4;
};
extern "C" {
extern const char lbl_802AF56C[],lbl_802AF57C[];extern const float lbl_8037B8F8;
void*fn_801EFA1C(void*,u32,const char*,const char*,int,int);
void OSInitThreadQueue(void*);signed char OSCreateThread(void*,void*(*)(void*),void*,void*,u32,int,u16);int OSResumeThread(void*);
void*fn_80288D00(void*);
void fn_8028AC20(StreamInitState*);
}
typedef char CheckStreamInitState[sizeof(StreamInitState)==0x4AD8?1:-1];
#endif
