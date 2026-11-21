#include "Game/engine_queue_reset.h"

static inline QueueResetTarget *resolve(const Handle_801F7F10 &handle)
{
    QueueResetEntry *entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    return entry->tag == handle.bits.tag ? entry->object : 0;
}

extern "C" void fn_80230DF8(QueueResetOwner *self, int index, signed char all)
{
    self->state = 0;
    self->flag5C = 0;
    self->flag5D = 0;
    for (int i = 0; i < self->count; ++i) {
        fn_801F7914(&self->handles[i], Handle_801F7F10());
    }
    self->count = 0;
    if (fn_801F7EB8(&self->parent))
        resolve(self->parent)->value = lbl_8037B1D4;
    if (all) {
        Handle_801F7F10 handle;
        if (index == -1) {
            for (int i = 0; i < self->size(); ++i)
                self->replace(handle, i);
        } else {
            self->replace(handle, index);
        }
    }
}
