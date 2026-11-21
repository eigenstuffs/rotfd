#include "Game/engine_owner_small.h"

void fn_8020EE10(struct EngineOwnerSmallFlagOwner* self)
{
    struct EngineOwnerSmallObject* object;
    self->enabled = 1;
    self->active = 0;
    object = engineOwnerSmallResolve(&self->handle);
    object->flags &= ~0x10000UL;
}
