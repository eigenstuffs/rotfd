#include "Game/engine_array_owner_cleanup.h"

static inline void destroyHandle(struct EngineOwnerHandle* handle)
{
    if (handle)
        __dt__15Handle_801F7F10Fv(handle, 0);
}

static inline void destroyItem(struct EngineOwnerHandleItem* item)
{
    if (item)
        destroyHandle(&item->handle);
}

static inline void destroyArray(struct EngineOwnerHandleArray* self)
{
    int i;
    if (self) {
        if (self->items) {
            for (i = 0; i < self->count; i++)
                destroyItem(&self->items[i]);
            if (self->items) {
                fn_8028FD50(lbl_8028F698, self->items, self->capacity * 4);
                self->items = 0;
            }
            self->items = 0;
        }
    }
}

struct EngineArrayOwnerHandles* fn_8023AC94(struct EngineArrayOwnerHandles* self, short deleting)
{
    if (self) {
        self->vptr10 = &lbl_802EC020;
        destroyArray(&self->array);
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
