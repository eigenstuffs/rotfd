#include "Game/owner_reset_action_views.h"

extern "C" void fn_80094EF0(ResetAction* self)
{
    fn_80055EE4(lbl_801E9D24.world->screen, 1);
    self->agent->flags30 &= ~0x200ULL;
}
