/* MetroTRK main entry; see docs/notes/MetroTRK-main_TRK.md. */
#include "trk_abi.h"
extern DSError TRKInitializeNub(void), TRKTerminateNub(void);
extern void TRKNubWelcome(void), TRKNubMainLoop(void);

static int TRK_mainError;

u8 TRKTargetCPUMinorType(void)
{
    return 0x54;
}

int TRK_main(void)
{
    TRK_mainError = TRKInitializeNub();
    if (!TRK_mainError) {
        TRKNubWelcome();
        TRKNubMainLoop();
    }
    return TRK_mainError = TRKTerminateNub();
}
