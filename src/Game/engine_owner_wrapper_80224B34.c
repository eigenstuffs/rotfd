#include "Game/engine_owner_wrappers.h"

int fn_80224B34(EngineOwnerWrapperFind* self, int index)
{
    int next = index + 1;
    if (next >= self->count)
        return -1;
    return fn_80207B94(&self->bits, 1, next);
}
