#include "Game/engine_owner_small.h"

void fn_80224C1C(struct EngineOwnerSmallMaskOwner* self, int index)
{
    slotF4__12ObjectMove_ZFv(self, index);
    *(unsigned long long*)(self->records + index * 0xA8 + 0x38) = self->flags;
}
