#include "Game/engine_group_record_update.h"

static inline GroupUpdateObject *resolve(const Handle_801F7F10 &handle)
{
    GroupUpdateEntry *entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    return entry->tag == handle.bits.tag ? entry->object : 0;
}

static inline void assign(Handle_801F7F10 *self, const Handle_801F7F10 &handle)
{
    fn_801F86C8(lbl_801E9D24.manager, self, -1);
    self->value = handle.value;
    fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
}

static inline void setFirst(GroupUpdateObject *object, const Handle_801F7F10 &handle)
{
    assign(&object->first, handle);
    fn_8023D648(object);
}

static inline void setSecond(GroupUpdateObject *object, const Handle_801F7F10 &handle)
{
    assign(&object->second, handle);
    fn_8023D648(object);
}

static inline GroupUpdateObject *resolveAlternate(const Handle_801F7F10 &handle)
{
    struct GroupUpdateByteManager { int count, capacity; char *entries; };
    GroupUpdateEntry *entry = (GroupUpdateEntry *)
        (((GroupUpdateByteManager *)lbl_801E9D24.manager)->entries + handle.bits.index * 16);
    return entry->tag == handle.bits.tag ? entry->object : 0;
}

extern "C" void fn_8021B230(GroupUpdateOwner *self, void *arg)
{
    GroupUpdateContext *context = &lbl_801E9D24;
    int offset;
    GroupUpdateRecord *record;
    int i;
    i = 0;
    offset = 0;
    for (; i < self->records.count; offset += 0x9C, ++i) {
        record = (GroupUpdateRecord *)((char *)self->records.data + offset);
        record->value94 = fn_801E5FDC(context->recordManager,
            &record->value80, 1, &record->handle98);
    }
    fn_8021D51C(self, arg);
    if (fn_801F7EB8(&self->second)) {
        GroupUpdateHandle handle;
        if (fn_801E5D78(context->recordManager,
            *(unsigned long *)((char *)self->records.data + self->selected * 0x9C + 0x94),
            &handle)) {
            setFirst(resolve(self->second), self->records.data[self->selected].handle98);
            setSecond(resolve(self->second), handle);
            fn_8023DE28(resolveAlternate(resolve(self->first)->child));
        }
    }
}
