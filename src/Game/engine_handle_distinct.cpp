#include "Game/engine_handle_distinct.h"

static inline bool sameObject(const EngineDistinctHandle& first, const EngineDistinctHandle& second)
{
    EngineDistinctObject* object = engineDistinctResolve(first);
    return object == engineDistinctResolve(second);
}

static inline void apply(const EngineDistinctHandle& handle, void* argument)
{
    engineDistinctResolve(handle)->slot24(argument);
}

extern "C" void fn_802459DC(EngineDistinctOwner* self, void* argument)
{
    if (self->count) {
        apply(self->items[0], argument);
        for (int i = 1; i < self->count; i++) {
            if (!sameObject(self->items[i - 1], self->items[i]) && fn_801F7EB8(&self->items[i]))
                engineDistinctResolve(self->items[i])->slot24(argument);
        }
    }
}
