#include "Game/engine_range_operations.h"

static inline RangeOpsNode *resolve(RangeOpsManager *manager, const RangeOpsHandle *handle)
{
    RangeOpsEntry *entry = &manager->entries[handle->index];
    if (entry->generation == handle->generation)
        return entry->object;
    return 0;
}

void fn_8023D8D8(RangeOpsNode *self)
{
    RangeOpsManager *manager = lbl_801E9D24.manager;
    RangeOpsNode *parent = resolve(manager, &self->parent);
    while (parent) {
        self = parent;
        parent = resolve(manager, &self->parent);
    }
    resolve(manager, &self->owner)->flags |= 8;
}
