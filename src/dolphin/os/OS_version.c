/* Dolphin SDK OS.c C fragment, GSQE78.
 * Adapted from pinned PrimeDecomp/prime; see reference/prime-sdk/PROVENANCE.md.
 */
#include "OS_abi.h"

extern __declspec(section ".sdata") char OSVersionFormat[];

#define DI_CONFIG_IDX 0x9
#define DI_CONFIG_CONFIG_MASK 0xFF
u32 __OSGetDIConfig(void) { return (__DIRegs[DI_CONFIG_IDX] & DI_CONFIG_CONFIG_MASK); }

void OSRegisterVersion(const char* id) { OSReport(OSVersionFormat, id); }
