#include "Game/owner_control_state_views.h"
extern "C" void fn_800944A0(ControlStateAgent* self, int state)
{
    fn_80094600(self);
    switch (state) {
    case 0: fn_8007D6A0(&self->controls, 0x1D); break;
    case 1: fn_8007D6A0(&self->controls, 0x1E); break;
    case 2: fn_8007D6A0(&self->controls, 0x1F); break;
    case 3: fn_8007D6A0(&self->controls, 0x20); break;
    case 4: fn_8007D6A0(&self->controls, 0x23); break;
    case 5: fn_8007D6A0(&self->controls, 0x2A); break;
    }
    ControlStateObject* object = (ControlStateObject*)resolveControlState(self->owner);
    if (object->state == 1) {
        object->active = 1;
        fn_8007D6A0(&self->controls, 0x22);
    }
    if (lbl_801E9D24.world->screen->active)
        fn_8007D6A0(&self->controls, 0x37);
    fn_8007D6A0(&self->controls, 0x34);
}
