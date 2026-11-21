#include "Game/owner_reset_action_views.h"

extern "C" void fn_800957F4(ResetAction* self)
{
    fn_8007D7F4(&self->agent->controls, 0);
    fn_8007D7F4(&self->agent->controls, 1);
    fn_8007D7F4(&self->agent->controls, 2);
    fn_8025795C(self->target, 1, 0);
    self->agent->velocity = game_vec3_zero;
}
