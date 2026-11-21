#include "Game/engine_group_membership.h"

extern "C" void fn_8021AC2C(MembershipOwner *self, unsigned char group)
{
    self->group = group;
    fn_80213A18(self);
    const Handle_801F7F10 &original = self->handle;
    MembershipHandle handle(original);
    fn_801E2074(lbl_801E9D24.groups + self->group * 0x4C, handle, 0);
}
