#include "Game/engine_range_dispatch.h"

static inline RangeDispatchNode *resolve(RangeDispatchManager *manager,
    const RangeDispatchHandle *handle)
{
    RangeDispatchEntry *entry = &manager->entries[handle->index];
    if (entry->generation == handle->generation)
        return entry->object;
    return 0;
}

void fn_8020EB54(RangeDispatchCallback *self, const RangeDispatchHandle *source)
{
    RangeDispatchContext *context = &lbl_801E9D24;
    RangeDispatchManager *manager = context->manager;
    RangeDispatchNode *object = resolve(manager, source);
    if (resolve(manager, &object->first)->type == 2) {
        fn_801F86C8(manager, &self->target, -1);
        self->target = *source;
        fn_801F86C8(context->manager, source, 1);
    }
}
