/* Private EXI ABI from SDK declarations and original hardware accesses. */
#ifndef ROTFD_EXI_ABI_H
#define ROTFD_EXI_ABI_H
#include "../os/OSContext_abi.h"
typedef signed long s32;
typedef volatile u32 vu32;
typedef volatile u16 vu16;
typedef signed long long OSTime;
typedef signed short __OSInterrupt;
typedef void (*__OSInterruptHandler)(__OSInterrupt, OSContext*);
#define TRUE 1
#define FALSE 0
#define OS_BASE_CACHED 0x80000000
#define OS_CONSOLE_MASK 0xf0000000
#define OS_CONSOLE_TDEV 0x20000000
#define EXI_READ 0
#define EXI_WRITE 1
#define EXI_FREQ_1M 0
#define EXI_STATE_ATTACHED 8
#define EXI_USB_ADAPTER 0x01010000
#define EXI_IS_VIEWER 0x05070000
extern volatile u32 __EXIRegs[15] : 0xCC006800;
extern u32 __OSBusClock : 0x800000F8;
#define OSTicksToMilliseconds(ticks) ((ticks) / (__OSBusClock / 4 / 1000))
extern OSTime OSGetTime(void);
extern u32 OSGetConsoleType(void);
extern void OSRegisterVersion(const char*);
extern void OSClearContext(OSContext*);
extern u32 __OSMaskInterrupts(u32), __OSUnmaskInterrupts(u32);
extern __OSInterruptHandler __OSGetInterruptHandler(__OSInterrupt), __OSSetInterruptHandler(__OSInterrupt, __OSInterruptHandler);
extern void *memmove(void*, const void*, u32);
#define OS_INTERRUPTMASK(interrupt) (0x80000000u >> (interrupt))
#define __OS_INTERRUPT_EXI_0_EXI 9
#define OS_INTERRUPTMASK_EXI_0_EXI OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_0_EXI)
#define __OS_INTERRUPT_EXI_0_TC 10
#define OS_INTERRUPTMASK_EXI_0_TC OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_0_TC)
#define __OS_INTERRUPT_EXI_0_EXT 11
#define OS_INTERRUPTMASK_EXI_0_EXT OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_0_EXT)
#define __OS_INTERRUPT_EXI_1_EXI 12
#define OS_INTERRUPTMASK_EXI_1_EXI OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_1_EXI)
#define __OS_INTERRUPT_EXI_1_TC 13
#define OS_INTERRUPTMASK_EXI_1_TC OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_1_TC)
#define __OS_INTERRUPT_EXI_1_EXT 14
#define OS_INTERRUPTMASK_EXI_1_EXT OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_1_EXT)
#define __OS_INTERRUPT_EXI_2_EXI 15
#define OS_INTERRUPTMASK_EXI_2_EXI OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_2_EXI)
#define __OS_INTERRUPT_EXI_2_TC 16
#define OS_INTERRUPTMASK_EXI_2_TC OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_2_TC)
#define __OS_INTERRUPT_PI_DEBUG 25
#define OS_INTERRUPTMASK_PI_DEBUG OS_INTERRUPTMASK(__OS_INTERRUPT_PI_DEBUG)
typedef void (*EXICallback)(s32 chan, OSContext *context);

EXICallback EXISetExiCallback(s32 channel, EXICallback callback);

void EXIInit(void);
BOOL EXILock(s32 channel, u32 device, EXICallback callback);
BOOL EXIUnlock(s32 channel);
BOOL EXISelect(s32 channel, u32 device, u32 frequency);
BOOL EXIDeselect(s32 channel);
BOOL EXIImm(s32 channel, void *buffer, s32 length, u32 type, EXICallback callback);
BOOL EXIImmEx(s32 channel, void *buffer, s32 length, u32 type);
BOOL EXIDma(s32 channel, void *buffer, s32 length, u32 type, EXICallback callback);
BOOL EXISync(s32 channel);
BOOL EXIProbe(s32 channel);
s32 EXIProbeEx(s32 channel);
BOOL EXIAttach(s32 channel, EXICallback callback);
BOOL EXIDetach(s32 channel);
u32 EXIGetState(s32 channel);
s32 EXIGetID(s32 channel, u32 device, u32* id);
void EXIProbeReset(void);


u32 EXIClearInterrupts(s32, BOOL, BOOL, BOOL);
#endif
