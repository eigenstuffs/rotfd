/* MetroTRK event loop. See docs/notes/MetroTRK-mainloop.md. */
#include "trk_abi.h"

static inline void TRKHandleRequestEvent(NubEvent* ev)
{
    TRKDispatchMessage(TRKGetBuffer(ev->fMessageBufferID));
}

static inline void TRKHandleSupportEvent(NubEvent* ev)
{
    TRKTargetSupportRequest();
}

static inline void TRKIdle(void)
{
    if (!TRKTargetStopped()) {
        TRKTargetContinue();
    }
}

void TRKNubMainLoop(void)
{
    NubEvent event;
    bool var_r31 = false;
    bool var_r30 = false;

    while (!var_r31) {
        if (TRKGetNextEvent(&event) != false) {
            var_r30 = false;
            switch (event.fType) {
            case kNullEvent:
                break;
            case kRequestEvent:
                TRKHandleRequestEvent(&event);
                break;
            case kShutdownEvent:
                var_r31 = true;
                break;
            case kBreakpointEvent:
            case kExceptionEvent:
                TRKTargetInterrupt(&event);
                break;
            case kSupportEvent:
                TRKHandleSupportEvent(&event);
                break;
            }
            TRKDestructEvent(&event);
        } else if (!var_r30 || *(u8*) gTRKInputPendingPtr != 0) {
            var_r30 = true;
            TRKGetInput();
        } else {
            TRKIdle();
            var_r30 = false;
        }
    }
}
