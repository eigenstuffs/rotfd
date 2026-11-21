#include "Game/state_collision_controls.h"

struct StateControl_802358AC {
    char unknown00[0x14];
    char first14[0x38];
    char second4C[0x28];
};

extern "C" {
void fn_801F6A7C(void*);
void fn_802358E8(void*);
}

extern "C" StateControl_802358AC* fn_802358AC(StateControl_802358AC* self)
{
    fn_801F6A7C(self->first14);
    fn_802358E8(self->second4C);
    return self;
}
