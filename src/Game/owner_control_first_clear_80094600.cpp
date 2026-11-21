#include "Game/owner_control_state_views.h"
extern "C" void fn_80094600(ControlStateAgent* self)
{
    if (fn_8007D604(&self->controls, 0x1D))
        fn_8007D7F4(&self->controls, 0x1D);
    else if (fn_8007D604(&self->controls, 0x1E))
        fn_8007D7F4(&self->controls, 0x1E);
    else if (fn_8007D604(&self->controls, 0x1F))
        fn_8007D7F4(&self->controls, 0x1F);
    else if (fn_8007D604(&self->controls, 0x20))
        fn_8007D7F4(&self->controls, 0x20);
    else if (fn_8007D604(&self->controls, 0x23))
        fn_8007D7F4(&self->controls, 0x23);
    else if (fn_8007D604(&self->controls, 0x2A))
        fn_8007D7F4(&self->controls, 0x2A);
}
