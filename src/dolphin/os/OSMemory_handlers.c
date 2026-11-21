/* Dolphin SDK memory-protection C fragment, GSQE78.
 * Adapted from the public doldecomp/melee SDK reconstruction;
 * see reference/melee-sdk/PROVENANCE.md and docs/notes/OSMemory.md.
 */
#include "OSMemory_abi.h"

BOOL OSMemoryOnReset(BOOL final)
{
    if (final != FALSE) {
        __MEMRegs[8] = 0xFF;
        __OSMaskInterrupts(0xF0000000);
    }
    return TRUE;
}

void MEMIntrruptHandler(__OSInterrupt interrupt, OSContext* context)
{
    u32 cause = __MEMRegs[0xF];
    u32 addr = ((__MEMRegs[0x12] & 0x3FF) << 16) | __MEMRegs[0x11];
    __MEMRegs[0x10] = 0;

    if (__OSErrorTable[0xF]) {
        __OSErrorTable[0xF](0xF, context, cause, addr);
        return;
    }

    __OSUnhandledException(0xF, context, cause, addr);
}

