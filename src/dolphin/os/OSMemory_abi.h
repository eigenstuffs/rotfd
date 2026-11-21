/* Local target ABI for the recovered C fragments of OSMemory.c. */
#ifndef ROTFD_OSMEMORY_ABI_H
#define ROTFD_OSMEMORY_ABI_H
#include "OSContext_abi.h"
#define FALSE 0
#define TRUE 1
typedef signed short __OSInterrupt;
typedef void (*__OSInterruptHandler)(__OSInterrupt, OSContext *);
typedef void (*OSErrorHandler)(u16, OSContext *, ...);
extern OSErrorHandler __OSErrorTable[17];
extern void __OSUnhandledException(__OSException, OSContext *, u32, u32);
extern u32 __OSMaskInterrupts(u32), __OSUnmaskInterrupts(u32);
extern __OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt, __OSInterruptHandler);
extern void Config24MB(void), Config48MB(void), RealMode(void (*)(void));
extern BOOL OSMemoryOnReset(BOOL);
extern void MEMIntrruptHandler(__OSInterrupt, OSContext *);
typedef BOOL (*OSResetFunction)(BOOL);
typedef struct OSResetFunctionInfo OSResetFunctionInfo;
struct OSResetFunctionInfo {
    OSResetFunction func;
    u32 priority;
    OSResetFunctionInfo *next, *prev;
};
extern void OSRegisterResetFunction(OSResetFunctionInfo *);
volatile u16 __MEMRegs[64] : 0xCC004000;
u32 __OSPhysicalMemSize : 0x80000028;
u32 __OSSimulatedMemSize : 0x800000F0;
static inline u32 OSGetPhysicalMemSize(void) { return __OSPhysicalMemSize; }
static inline u32 OSGetConsoleSimulatedMemSize(void) { return __OSSimulatedMemSize; }
#endif
