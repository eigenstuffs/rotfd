/* Dolphin SDK reset C fragment, GSQE78.
 * Adapted from the public doldecomp/melee SDK reconstruction;
 * see reference/melee-sdk/PROVENANCE.md and docs/notes/OSReset.md.
 * Processor reset assembly remains original fallback.
 */
#include "OSReset_abi.h"

static inline int CallResetFunctions(int final) {
    struct OSResetFunctionInfo * info;
    int err = 0;

    for(info = OSResetFunctionQueue.head; info; info = info->next) {
        err |= !info->func(final);
    }
    err |= !__OSSyncSram();
    if (err) {
        return 0;
    }
    return 1;
}

int __PADDisableRecalibration(int);

static inline void CancelThreads(void)
{
    OSThread* thread = __OSActiveThreadQueue.head;
    while (thread != NULL) {
        OSThread* next = thread->linkActive.next;
        switch (thread->state) {
        case 1:
        case 4:
            OSCancelThread(thread);
        default:
            break;
        }
        thread = next;
    }
}

void __OSDoHotReset(int arg0)
{
    OSDisableInterrupts();
    __VIRegs[1] = 0;
    ICFlashInvalidate();
    OSResetHardware(arg0 << 3);
}

void OSResetSystem(int reset, unsigned long resetCode, int forceMenu) {
    int rc;
    int enabled;
    int padcal;
    struct OSSram * sram;
    u8 _[8];

    OSDisableScheduler();
    __OSStopAudioSystem();

    if (reset == 2) {
        padcal = __PADDisableRecalibration(1);
    }

    do {} while (CallResetFunctions(0) == 0);

    if ((reset == 1 && (forceMenu != 0))) {
        sram = __OSLockSram();
        sram->flags |= 0x40;
        __OSUnlockSram(1);
        do {} while(__OSSyncSram() == 0);
    }
    enabled = OSDisableInterrupts();
    rc = CallResetFunctions(1);
    LCDisable();
    ASSERTLINE(0x117, rc);
    if (reset == 1) {
        enabled = OSDisableInterrupts();
        __VIRegs[1] = 0;
        ICFlashInvalidate();
        OSResetHardware(resetCode * 8);
    } else if (reset == 0) {
        CancelThreads();
        OSEnableScheduler();
        __OSReboot(resetCode, forceMenu);
    }

    CancelThreads();

    memset((void*) 0x80000040, 0, 0x8C);
    memset((void*) 0x800000D4, 0, 0x14);
    memset((void*) 0x800000F4, 0, 4);
    memset((void*) 0x80003000, 0, 0xC0);
    memset((void*) 0x800030C8, 0, 0xC);
    memset((void*) 0x800030E2, 0, 1);

    __PADDisableRecalibration(padcal);
}

u8 unk : 0x800030E2;

unsigned long OSGetResetCode() {
    if (unk != 0) {
        return 0x80000000;
    }
    return (__PIRegs[9] & ~7) >> 3;
}
