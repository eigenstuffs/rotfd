#include "Game/engine_range_operations.h"

static inline RangeOpsNode *resolve(RangeOpsManager *manager, const RangeOpsHandle *handle)
{
    RangeOpsEntry *entry = &manager->entries[handle->index];
    if (entry->generation == handle->generation)
        return entry->object;
    return 0;
}

static inline int equal(RangeOpsManager *manager, const RangeOpsHandle *first,
    const RangeOpsHandle *second)
{
    RangeOpsNode *object = resolve(manager, first);
    return object == resolve(manager, second);
}

RangeOpsHandle *fn_8023A5DC(RangeOpsHandleArray *self, const RangeOpsHandle *target)
{
    RangeOpsManager *manager = lbl_801E9D24.manager;
    RangeOpsHandle *items;
    int i;
    for (i = 0; i < self->count; i++) {
        RangeOpsNode *object;
        items = self->items;
        object = resolve(manager, &items[i]);
        if (equal(manager, target, &object->related))
            return &items[i];
    }
    return self->items;
}
