/* Partial native state views for the two stepping request entry points.
 *
 * The original reads the stored type byte again before deciding whether to
 * decrement the step count.  This private access view preserves that one
 * observed read of request/interrupt-shared state.  It does not establish the
 * qualifier used by the original complete translation unit.
 */
typedef unsigned long u32;
typedef unsigned char u8;
typedef int DSError;
typedef int bool;

struct StepStatus {
    bool active;
    volatile u8 type;
    u32 count;
    u32 rangeStart;
    u32 rangeEnd;
};
struct CPUState {
    unsigned char opaque[0x1F8];
    u32 msr;
};
struct TargetState {
    unsigned char opaque[0x98];
    bool stopped;
};

typedef char StepStatusSizeCheck[sizeof(struct StepStatus) == 20 ? 1 : -1];
typedef char CPUStateViewSizeCheck[sizeof(struct CPUState) == 0x1FC ? 1 : -1];
typedef char TargetStateViewSizeCheck[sizeof(struct TargetState) == 0x9C ? 1 : -1];

extern struct StepStatus gTRKStepStatus;
extern struct CPUState gTRKCPUState;
extern struct TargetState gTRKState;

static inline DSError enableTrace(bool enabled)
{
    if (enabled) {
        gTRKCPUState.msr |= 0x400;
    } else {
        gTRKCPUState.msr &= ~0x400;
    }
    return 0;
}

static inline DSError doStep(void)
{
    u32 type;
    gTRKStepStatus.active = 1;
    enableTrace(1);
    type = gTRKStepStatus.type;
    if (type == 0 || type == 16) {
        gTRKStepStatus.count--;
    }
    gTRKState.stopped = 0;
    return 0;
}

DSError TRKTargetSingleStep(u32 count, bool stepOver)
{
    DSError error = 0;
    if (stepOver) {
        error = 0x703;
    } else {
        gTRKStepStatus.type = 0;
        gTRKStepStatus.count = count;
        error = doStep();
    }
    return error;
}

DSError TRKTargetStepOutOfRange(u32 start, u32 end, bool stepOver)
{
    DSError error = 0;
    if (stepOver) {
        error = 0x703;
    } else {
        gTRKStepStatus.type = 1;
        gTRKStepStatus.rangeStart = start;
        gTRKStepStatus.rangeEnd = end;
        error = doStep();
    }
    return error;
}
