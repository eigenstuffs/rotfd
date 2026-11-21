#include "Game/engine_range_dispatch.h"

static inline RangeDispatchNode *resolve(RangeDispatchManager *manager,
    const RangeDispatchHandle *handle)
{
    RangeDispatchEntry *entry = &manager->entries[handle->index];
    if (entry->generation == handle->generation)
        return entry->object;
    return 0;
}

void fn_8020E394(RangeDispatchCallback *self)
{
    RangeDispatchManager *manager;
    RangeDispatchNode *object;
    fn_8020EE70(self);
    self->value30 = lbl_8037AAB4;
    self->value2C = lbl_8037AAB4;
    manager = lbl_801E9D24.manager;
    object = resolve(manager, &self->handle);
    if (resolve(manager, &object->first)->flagsB4 & 0x10) {
        self->active = 0;
        fn_8020EDB0(self);
    }
}
