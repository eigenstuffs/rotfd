#include "Game/engine_group_membership.h"

extern "C" void fn_8021AB88(MembershipOwner *self)
{
    fn_802139D8(self);
    const Handle_801F7F10 &original = self->handle;
    MembershipHandle handle(original);
    fn_801E1F3C(lbl_801E9D24.groups + self->group * 0x4C, handle);
}
