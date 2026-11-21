#include "Game/owner_reset_action_views.h"

extern "C" void fn_80094B14(ResetAction* self)
{
    fn_8007D7F4(&self->agent->controls, 0);
    fn_8007D7F4(&self->agent->controls, 1);
    fn_8007D7F4(&self->agent->controls, 2);
    self->target->flags38 &= ~0x20000ULL;
    fn_8025795C(self->target, 1, 0);
}
