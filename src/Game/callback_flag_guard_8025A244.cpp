#include "Game/callback_virtual_handles_internal.h"

// Observed owner fields shared by the two activation guard checks.
struct CallbackGuardOwner {
    char unknown00[0x38];
    unsigned long long flags;
    char unknown40[0x30];
    CallbackVirtualHandle handle70;

    signed char hasFlag(unsigned long long mask) const {
        if (flags & mask)
            return 1;
        return 0;
    }
};

extern "C" void fn_8025A244(CallbackGuardOwner* self) {
    if (!self->hasFlag(0x20000ULL) && !(self->flags & 0x10000ULL)) {
        if (fn_801F7EB8(&self->handle70))
            fn_802139D8(resolveVirtual(self->handle70));
        fn_802573E4(self);
    }
}
