#include "Game/engine_owner_small.h"

void fn_8020ED58(struct EngineOwnerSmallFlagOwner* self)
{
    struct EngineOwnerSmallObject* object;
    self->active = 0;
    object = engineOwnerSmallResolve(&self->handle);
    object->flags &= ~0x10000UL;
}
