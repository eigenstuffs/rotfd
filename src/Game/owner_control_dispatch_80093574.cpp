#include "Game/owner_control_dispatch_views.h"
extern "C" void fn_80093574(StateDispatchAgent* self)
{
    if (fn_8007D604(&self->controls, 0x1D))
        fn_8007DD0C(&self->controls, 0x1D)->dispatch();
    else if (fn_8007D604(&self->controls, 0x1E))
        fn_8007DD0C(&self->controls, 0x1E)->dispatch();
    else if (fn_8007D604(&self->controls, 0x1F))
        fn_8007DD0C(&self->controls, 0x1F)->dispatch();
    else if (fn_8007D604(&self->controls, 0x20))
        fn_8007DD0C(&self->controls, 0x20)->dispatch();
    else if (fn_8007D604(&self->controls, 0x23))
        fn_8007DD0C(&self->controls, 0x23)->dispatch();
    else if (fn_8007D604(&self->controls, 0x2A))
        fn_8007DD0C(&self->controls, 0x2A)->dispatch();
}
