#include "Game/engine_owner_wrappers.h"

void fn_80230978(EngineOwnerWrapperFlags* self)
{
    fn_80227A14(self);
    self->flags &= ~0x200ULL;
}
