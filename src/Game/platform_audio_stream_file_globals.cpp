#include "Game/platform_audio_stream_lifetime_internal.h"
extern "C" {char lbl_8035E970[60];signed char lbl_8035E9AC[32];}

// Shared first-read cache used by the streaming request dispatcher.
// Four bytes of following linker alignment retain original ownership.
extern "C" char lbl_8035E9CC[0x10000];
char lbl_8035E9CC[0x10000];
