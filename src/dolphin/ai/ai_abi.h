/* Local AI register and callback ABI from the public Dolphin SDK references. */
#ifndef ROTFD_AI_ABI_H
#define ROTFD_AI_ABI_H
#include "../os/OSContext_abi.h"
typedef signed short s16;
typedef signed long s32;
typedef volatile s32 vs32;
typedef long long OSTime;
#define TRUE 1
#define FALSE 0
#define SET_FLAG(value, mask) ((value) |= (mask))
#define RESET_FLAG(value, mask) ((value) &= ~(mask))
extern const u32 __OSBusClock : 0x800000F8;
#define OSNanosecondsToTicks(nsec) (((nsec) * ((__OSBusClock / 4) / 125000)) / 8000)
#define OS_INTERRUPTMASK_DSP_AI 0x04000000
#define OS_INTERRUPTMASK_AI 0x00800000
typedef void (*__OSInterruptHandler)(s16, OSContext *);
extern void OSRegisterVersion(const char *), OSClearContext(OSContext *);
extern __OSInterruptHandler __OSSetInterruptHandler(s16, __OSInterruptHandler);
extern u32 __OSUnmaskInterrupts(u32);
extern OSTime OSGetTime(void);
extern volatile u16 __DSPRegs[32] : 0xCC005000;
extern volatile u32 __AIRegs[4] : 0xCC006C00;
#define DSP_DMA_START_HI    (24) // DMA start address
#define DSP_DMA_START_LO    (25)
#define DSP_DMA_CONTROL_LEN (27)
#define DSP_DMA_BYTES_LEFT  (29)
#define DSP_DMA_START_FLAG (0x8000) // set to start DSP
#define AI_CONTROL        (0) // control
#define AI_VOLUME         (1) // volume
#define AI_SAMPLE_COUNTER (2) // number of stereo samples output
#define AI_INTRPT_TIMING  (3) // interrupt timing
#define AI_CONTROL_PLAY_STATE          (0x1)
#define AI_CONTROL_STREAM_SAMPLE_RATE  (0x2)
#define AI_CONTROL_DSP_SAMPLE_COUNT    (0x4)
#define AI_CONTROL_UNKNOWN8            (0x8)
#define AI_CONTROL_STREAM_SAMPLE_COUNT (0x20)
#define AI_CONTROL_DSP_SAMPLE_RATE     (0x40)
typedef void (*AISCallback)(u32 count);
typedef void (*AIDCallback)();

/////////////// AI FUNCTIONS ///////////////
AIDCallback AIRegisterDMACallback(AIDCallback callback);
void AIInitDMA(u32 start_addr, u32 length);
BOOL AIGetDMAEnableFlag(void);
void AIStartDMA(void);
void AIStopDMA(void);
u32 AIGetDMABytesLeft(void);
u32 AIGetDMAStartAddr(void);
u32 AIGetDMALength(void);
u32 AIGetDSPSampleRate(void);
void AISetDSPSampleRate(u32 rate);
AISCallback AIRegisterStreamCallback(AISCallback callback);
u32 AIGetStreamSampleCount(void);
u32 AIGetStreamTrigger(void);
void AISetStreamPlayState(u32 state);
u32 AIGetStreamPlayState(void);
void AISetStreamSampleRate(u32 rate);
u32 AIGetStreamSampleRate(void);
void AISetStreamVolLeft(u8 vol);
void AISetStreamVolRight(u8 vol);
u8 AIGetStreamVolLeft(void);
u8 AIGetStreamVolRight(void);
void AIInit(u8* stack);
BOOL AICheckInit(void);
void AIReset(void);


#endif
