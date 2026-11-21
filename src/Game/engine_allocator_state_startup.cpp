#include "Game/engine_allocator_state_startup.h"

extern "C" void fn_80290B50()
{
    lbl_8028F698.words00[0] = 0;
    lbl_8028F698.words00[1] = 0;
    lbl_8028F698.words00[2] = 0;
    lbl_8028F698.words00[3] = 0;
    lbl_8028F698.words00[4] = 0;
    lbl_8028F698.words00[5] = 0;
    lbl_8028F698.bytes18 = 0x400;
    lbl_8028F698.bytes1C = 0x200;
}

__declspec(section ".ctors")
static void* const allocator_state_startup_reference = fn_80290B50;
