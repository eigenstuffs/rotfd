// Menu2D destruction, render-slot membership and accumulated-time pulse.
#include "menu2d_lifecycle_internal.h"

Menu2D_80216C9C::~Menu2D_80216C9C() {
    vtable = __vt__15Menu2D_80216C9C;
}

extern "C" void fn_802159A0(Menu2D_80216C9C* self) {
    fn_802139D8(reinterpret_cast<Activable_Z*>(self));
    fn_801E1F3C(&lbl_801E9D24.renderSlots[self->selector],
               MenuHandle(self->getIdentity()));
}

extern "C" void fn_80215A44(Menu2D_80216C9C* self, unsigned char selector) {
    self->selector = selector;
    fn_80213A18(reinterpret_cast<Activable_Z*>(self));
    fn_80216228(self);
    fn_801E2074(&lbl_801E9D24.renderSlots[self->selector],
               MenuHandle(self->getIdentity()), 0);
}

extern "C" void fn_80215AF8(Menu2D_80216C9C* self, float) {
    float value = lbl_8037AD68 *
        (lbl_8037AD6C + fn_80284FA8(lbl_8037AD70 * self->accumulated));
    self->pulse = value * lbl_8037AD74;
}
