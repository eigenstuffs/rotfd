#include "Game/engine_handle_transfer.h"

static inline void *resolve(const Handle_801F7F10 &handle)
{
    TransferEntry *entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    return entry->tag == handle.bits.tag ? entry->object : 0;
}

extern "C" void fn_80230A34(TransferOwner *self, const Handle_801F7F10 *other, void *arg)
{
    void *object;
    object = resolve(TransferOwnerHandle(self->handle));
    TransferHandle handle((TransferTempHandle(*other)));
    fn_8023297C(object, handle, arg, self->flag);
    self->flag = 1;
}
