#include "Game/engine_range_dispatch.h"

static inline RangeDispatchNode *resolve(RangeDispatchManager *manager,
    const RangeDispatchHandle *handle)
{
    RangeDispatchEntry *entry = &manager->entries[handle->index];
    if (entry->generation == handle->generation)
        return entry->object;
    return 0;
}

void fn_8020EDB0(RangeDispatchCallback *self)
{
    self->state = 1;
    resolve(lbl_801E9D24.manager, &self->handle)->flags120 |= 0x10000;
}
