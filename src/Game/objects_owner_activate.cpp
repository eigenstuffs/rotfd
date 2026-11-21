#include "objects_root_callbacks_internal.h"

extern "C" void fn_802139D8(Activable_Z* self) {
    if (self->field18) {
        self->field18 = 0;
        self->slot24();
    }
}

extern "C" void fn_80213A18(Activable_Z* self) {
    if (!self->field18) {
        self->field18 = 1;
        self->slot20();
    }
}
