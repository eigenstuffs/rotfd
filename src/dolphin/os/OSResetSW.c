#include "OSContext_abi.h"
typedef signed short __OSInterrupt;
typedef unsigned long long u64;
typedef signed long long OSTime;
typedef void (*OSResetCallback)(void);
#define OS_BASE_CACHED 0x80000000
#define TRUE 1
#define FALSE 0
volatile u32 __PIRegs[12] : 0xCC003000;
u32 __OSBusClock : 0x800000F8;
#define OS_TIMER_CLOCK (__OSBusClock / 4)
#define OSMicrosecondsToTicks(usec) ((usec) * (OS_TIMER_CLOCK / 125000) / 8)
#define OSMillisecondsToTicks(msec) ((msec) * (OS_TIMER_CLOCK / 1000))
#define OSSecondsToTicks(sec) ((sec) * OS_TIMER_CLOCK)
#define OSTicksToSeconds(ticks) ((ticks) / OS_TIMER_CLOCK)
#define OS_INTERRUPTMASK_PI_RSW 0x200
extern u32 __OSMaskInterrupts(u32);
extern OSTime __OSGetSystemTime(void);
u8 GameChoice : (OS_BASE_CACHED | 0x30E3);

extern u64 __OSStartTime;

static OSResetCallback ResetCallback;
static BOOL Down;
static BOOL LastState;
static OSTime HoldUp;
static OSTime HoldDown;

void __OSResetSWInterruptHandler(__OSInterrupt exception,
                                 struct OSContext* context)
{
    OSResetCallback callback;

    HoldDown = __OSGetSystemTime();
    while (__OSGetSystemTime() - HoldDown < OSMicrosecondsToTicks(100)
           && !(__PIRegs[0] & 0x00010000)) {
        ;
    }
    if (!(__PIRegs[0] & 0x00010000)) {
        LastState = Down = TRUE;
        __OSMaskInterrupts(OS_INTERRUPTMASK_PI_RSW);
        if (ResetCallback) {
            callback      = ResetCallback;
            ResetCallback = NULL;
            callback();
        }
    }
    __PIRegs[0] = 2;
}

BOOL OSGetResetButtonState(void)
{
    BOOL enabled = OSDisableInterrupts();
    BOOL state;
    OSTime now = __OSGetSystemTime();
    u32 reg    = __PIRegs[0];

    if (!(reg & 0x00010000)) {
        if (!Down) {
            Down     = TRUE;
            state    = HoldUp ? TRUE : FALSE;
            HoldDown = now;
        } else {
            state = HoldUp || (OSMicrosecondsToTicks(100) < now - HoldDown)
                        ? TRUE
                        : FALSE;
        }
    } else if (Down) {
        Down  = FALSE;
        state = LastState;
        if (state) {
            HoldUp = now;
        } else {
            HoldUp = 0;
        }
    } else if (HoldUp && (now - HoldUp < OSMillisecondsToTicks(40))) {
        state = TRUE;
    } else {
        state  = FALSE;
        HoldUp = 0;
    }

    LastState = state;

    if (GameChoice & 0x3F) {
        OSTime fire = (GameChoice & 0x3F) * 60;
        fire        = __OSStartTime + OSSecondsToTicks(fire);
        if (fire < now) {
            now -= fire;
            now = OSTicksToSeconds(now) / 2;
            if ((now & 1) == 0) {
                state = TRUE;
            } else {
                state = FALSE;
            }
        }
    }

    OSRestoreInterrupts(enabled);
    return state;
}

BOOL OSGetResetSwitchState(void) { return OSGetResetButtonState(); }
