#include "Game/owner_control_state_views.h"
extern "C" signed char fn_800946FC(ControlStateAgent* self)
{
    if (!self->enabled) return 0;
    if (!(fn_8007D604(&self->controls, 9) || fn_8007D604(&self->controls, 0xA)
        || fn_8007D604(&self->controls, 0xB) || fn_8007D604(&self->controls, 0xC))) return 0;
    if (self->velocityY < lbl_80378BAC) return 0;
    if (fn_8007D604(&self->controls, 0xB)) {
        if (fn_801F7EB8(&self->related)) return 0;
        float limit = lbl_80378BEC * self->limit;
        if (self->angularY > limit || self->movementY > limit) return 0;
    }
    return 1;
}
