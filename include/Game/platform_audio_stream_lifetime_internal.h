#ifndef GAME_PLATFORM_AUDIO_STREAM_LIFETIME_INTERNAL_H
#define GAME_PLATFORM_AUDIO_STREAM_LIFETIME_INTERNAL_H
#include "Game/platform_audio_stream_internal.h"
struct StreamingLifetimeState {
 char unknown00[0x338];char thread[0x318];char unknown650[0x20];void*allocation670;
 char unknown674[0x4460];void*allocation4AD4;
};
extern "C" {
extern signed char lbl_8035E9AC[32];extern char lbl_8035E970[60];
void OSCancelThread(void*);void OSInitMutex(void*);
StreamingLifetimeState*fn_8028AF48(StreamingLifetimeState*,short);
StreamingLifetimeState*fn_8028AFF0(StreamingLifetimeState*);
}
#endif
