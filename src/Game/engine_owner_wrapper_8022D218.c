#include "Game/engine_owner_wrappers.h"

void fn_8022D218(EngineOwnerWrapperFlags* self)
{
    fn_80224888(self);
    self->flags &= ~0x1400ULL;
}
