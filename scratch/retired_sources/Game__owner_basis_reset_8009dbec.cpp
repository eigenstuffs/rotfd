#include "Game/owner_basis_motion_views.h"
extern "C" void fn_8009DBEC(BasisMotionAgent*self)
{
    fn_8009BEE8(self);
    fn_8007DCDC(&self->controls);
    self->flags &= ~0x81FFFE00ULL;
    self->flags |= 0x400;
    self->flags |= 0x200;
}
