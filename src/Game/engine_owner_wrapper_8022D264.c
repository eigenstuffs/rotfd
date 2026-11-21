#include "Game/engine_owner_wrappers.h"

void fn_8022D264(EngineOwnerWrapperFlags* self)
{
    fn_80224A10(self);
    self->flags &= ~0x1400ULL;
}
