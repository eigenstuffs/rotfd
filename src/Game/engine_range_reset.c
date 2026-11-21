#include "Game/engine_range_dispatch.h"

static inline RangeDispatchNode *resolve(RangeDispatchManager *manager,
    const RangeDispatchHandle *handle)
{
    RangeDispatchEntry *entry = &manager->entries[handle->index];
    if (entry->generation == handle->generation)
        return entry->object;
    return 0;
}

void fn_8020EE70(RangeDispatchCallback *self)
{
    RangeDispatchContext *context;
    RangeDispatchManager *manager;
    RangeDispatchNode *object;
    slot34__13Manipulator_ZFv(self);
    self->active = 1;
    self->state = 0;
    context = &lbl_801E9D24;
    resolve(context->manager, &self->handle)->flags120 &= ~0x10000;
    manager = context->manager;
    object = resolve(manager, &self->handle);
    fn_802525F0(resolve(manager, &object->second));
}
