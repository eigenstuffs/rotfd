#include "Game/owner_control_guard_views.h"
extern "C" void fn_800942B0(ControlGuardAgent* self, void* list)
{
    fn_80286058(list, 0x71);
    if (fn_8007D604(&self->controls, 0) || fn_8007D604(&self->controls, 0x35)
        || fn_8007D604(&self->controls, 0x38) || fn_8007D604(&self->controls, 1)
        || fn_8007D604(&self->controls, 2))
        fn_8007D6A0(&self->controls, 0xD);
    else if (fn_8007D604(&self->controls, 3))
        fn_8007D6A0(&self->controls, 4);
}
