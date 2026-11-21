#ifndef GAME_PLATFORM_AUDIO_STREAM_RELEASE_INTERNAL_H
#define GAME_PLATFORM_AUDIO_STREAM_RELEASE_INTERNAL_H
extern "C" {
#include "ax/ax_abi.h"
}
struct StreamReleaseRecord {
 u32 unknown00;char fileInfo[0x3C];u32 unknown40,unknown44,unknown48,unknown4C,unknown50;
 u32 flags,unknown58;
};
struct StreamReleaseVoice {
 AXVPB*voice[2];u32 unknown08;void*unknown0C;u32 unknown10,unknown14,unknown18;
 char unknown1C[0x18];u32 unknown34,unknown38;
};
struct StreamReleaseState {
 StreamReleaseRecord records[6];StreamReleaseVoice voices[6];char unknown390[0x46E4];char names[6][16];
};
struct AudioDiagnosticGlobals {char unknown00[0x110];void*logger;};
extern "C" {
extern AudioDiagnosticGlobals lbl_801E9D24;int fn_801F4520(const char*,const char*);int DVDClose(void*);void*memset(void*,int,u32);
extern signed char lbl_8035E9AC[32];extern const char lbl_802AF640[16],lbl_802AF650[16];extern char lbl_801EF5C8[];
void fn_801FA014(void*,const char*,...);void fn_801EF610(void*,void*);
void MIXReleaseChannel(AXVPB*);void AXFreeVoice(AXVPB*);
void fn_8028A4F0(void*,int);
}
#endif
