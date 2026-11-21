/* Dolphin SDK memory-protection C fragment, GSQE78.
 * Adapted from the public doldecomp/melee SDK reconstruction;
 * see reference/melee-sdk/PROVENANCE.md and docs/notes/OSMemory.md.
 */
#include "OSMemory_abi.h"

static OSResetFunctionInfo ResetFunctionInfo = {
    OSMemoryOnReset,
    0x7F,
};

void __OSInitMemoryProtection(void)
{
    u8 _[40];

    u32 simulated_mem = OSGetConsoleSimulatedMemSize();
    int enabled = OSDisableInterrupts();
    if (simulated_mem <= 24 * 1024 * 1024) {
        RealMode(Config24MB);
    } else if (simulated_mem <= 48 * 1024 * 1024) {
        RealMode(Config48MB);
    }
    __MEMRegs[16] = 0;
    __MEMRegs[8] = 0xFF;
    __OSMaskInterrupts(0xF0000000);
    __OSSetInterruptHandler(0, MEMIntrruptHandler);
    __OSSetInterruptHandler(1, MEMIntrruptHandler);
    __OSSetInterruptHandler(2, MEMIntrruptHandler);
    __OSSetInterruptHandler(3, MEMIntrruptHandler);
    __OSSetInterruptHandler(4, MEMIntrruptHandler);
    OSRegisterResetFunction(&ResetFunctionInfo);
    simulated_mem = OSGetConsoleSimulatedMemSize();
    if (simulated_mem < OSGetPhysicalMemSize() &&
        simulated_mem == 24 * 1024 * 1024) {
        __MEMRegs[20] = 2;
    }
    __OSUnmaskInterrupts(0x08000000);
    OSRestoreInterrupts(enabled);
}
