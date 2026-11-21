#include "Game/engine_queue_grid_reset.h"

static inline QueueGridResetTarget *resolve(const Handle_801F7F10 &handle)
{
    QueueGridResetEntry *entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    return entry->tag == handle.bits.tag ? entry->object : 0;
}

extern "C" void fn_80231330(QueueGridResetOwner *self, int index, signed char all)
{
    if (fn_801F7EB8(&self->parent))
        resolve(self->parent)->value = lbl_8037B1D8;
    Handle_801F7F10 handle;
    if (index == -1) {
        for (int row = 0; row < 4; ++row) {
            self->state[row] = 0;
            self->flag180[row] = 0;
            self->flag184[row] = 0;
            for (int i = 0; i < self->count[row]; ++i)
                fn_801F7914(&self->handles[row][i], Handle_801F7F10());
            if (all)
                self->replace(handle, row);
            self->count[row] = 0;
        }
    } else {
        self->state[index] = 0;
        self->flag180[index] = 0;
        self->flag184[index] = 0;
        for (int i = 0; i < self->count[index]; ++i)
            fn_801F7914(&self->handles[index][i], Handle_801F7F10());
        if (all)
            self->replace(handle, index);
        self->count[index] = 0;
    }
}
