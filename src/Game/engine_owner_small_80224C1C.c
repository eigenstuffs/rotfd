#include "Game/engine_owner_small.h"

void fn_80224C1C(struct EngineOwnerSmallMaskOwner* self, int index)
{
    fn_8021FC00(self, index);
    *(unsigned long long*)(self->records + index * 0xA8 + 0x38) = self->flags;
}
