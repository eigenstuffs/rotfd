/* Dolphin AX initialization. See docs/notes/AX.md. */
#include "ax_abi.h"
char* __AXVersion = "<< Dolphin SDK - AX\trelease build: Sep  5 2002 05:34:31 (0x2301) >>";


void AXInit(void) {
    OSRegisterVersion(__AXVersion);
    __AXAllocInit();
    __AXVPBInit();
    __AXSPBInit();
    __AXAuxInit();
    __AXClInit();
    __AXOutInit();
}

void AXQuit(void) {
    __AXAllocQuit();
    __AXVPBQuit();
    __AXSPBQuit();
    __AXAuxQuit();
    __AXClQuit();
    __AXOutQuit();
}
