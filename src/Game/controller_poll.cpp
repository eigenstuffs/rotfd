#include "Game/controller_poll_internal.h"

extern "C" void fn_802763D0(PollView* self) {
    unsigned long mask = 0;
    for (unsigned int i = 0; i < self->count; ++i) mask |= lbl_802ED6E8[i];
    if (mask) PADRecalibrate(mask);
}

extern "C" void fn_802764B0(PollView* self) {
    PADRead(self->status);
    for (short i = 0; i < self->count; ++i) {
        self->records[i].reset();
        fn_80275FC8(self, i);
    }
}
