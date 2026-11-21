#include "Game/engine_queue_transfer.h"

static inline void *resolve(const Handle_801F7F10 &handle)
{
    QueueTransferEntry *entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    return entry->tag == handle.bits.tag ? entry->object : 0;
}

extern "C" void fn_802316F8(QueueTransferOwner *self, const Handle_801F7F10 *other, int index)
{
    void *object;
    object = resolve(QueueTransferOwnerHandle(self->handle));
    QueueTransferHandle handle((QueueTransferTempHandle(*other)));
    fn_8023297C(object, handle, index, self->flag);
    self->flag = 1;
}
