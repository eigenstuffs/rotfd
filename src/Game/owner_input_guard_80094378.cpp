#include "Game/owner_control_guard_views.h"
extern "C" void fn_80094378(ControlGuardAgent* self)
{
    bool active = false;
    if (fn_8007D604(&self->controls, 0xD) || fn_8007D604(&self->controls, 4)) {
        fn_800B7214(lbl_801E9D24.input, 0xD, &active, 0);
        if (!active) self->enabled40A = 1;
    }
    active = false;
    fn_800B7214(lbl_801E9D24.input, 3, &active, 0);
    if (!active && fn_8007D604(&self->controls, 0x20) && fn_8007D604(&self->controls, 0x12))
        fn_8007D6A0(&self->controls, 0);
    active = false;
    fn_800B7214(lbl_801E9D24.input, 0xC, &active, 0);
    if (!active && self->enabled404) self->enabled404 = 0;
}
