#include "Game/engine_handle_property.h"

void fn_80248CAC(struct EnginePropertyOwner* self, float value)
{
    int i;
    for (i = 0; i < self->count; i++)
        enginePropertyResolve(&self->items[i])->property = value;
}
