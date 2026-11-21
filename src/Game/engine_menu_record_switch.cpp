#include "Game/engine_menu_record_switch.h"

static inline MenuRecordSwitchObject *resolve(const Handle_801F7F10 &handle)
{
    MenuRecordSwitchEntry *entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    return entry->tag == handle.bits.tag ? entry->object : 0;
}

static inline void assign(Handle_801F7F10 *self, const Handle_801F7F10 &handle)
{
    fn_801F86C8(lbl_801E9D24.manager, self, -1);
    self->value = handle.value;
    fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
}

static inline void setFirst(MenuRecordSwitchObject *object, const Handle_801F7F10 &handle)
{
    assign(&object->first, handle);
    fn_8023D648(object);
}

static inline void setSecond(MenuRecordSwitchObject *object, const Handle_801F7F10 &handle)
{
    assign(&object->second, handle);
    fn_8023D648(object);
}

static inline MenuRecordSwitchObject *resolveAlternate(const Handle_801F7F10 &handle)
{
    struct MenuRecordSwitchByteManager { int count, capacity; char *entries; };
    MenuRecordSwitchEntry *entry = (MenuRecordSwitchEntry *)
        (((MenuRecordSwitchByteManager *)lbl_801E9D24.manager)->entries + handle.bits.index * 16);
    return entry->tag == handle.bits.tag ? entry->object : 0;
}


extern "C" void fn_8021ACD8(MenuRecordSwitchOwner* self) {
    if (fn_801F7EB8(&self->second) && self->previous != self->selected) {
        MenuRecordSwitchHandle handle;
        const MenuRecordSwitchRecord& previous = self->records.data[self->previous];
        fn_801E5C1C(lbl_801E9D24.recordManager, previous.value94,
            &((MenuRecordSwitchObject*)menuRecordResolveMessage(self->second))->second);
        if (fn_801E5D78(lbl_801E9D24.recordManager,
            *(unsigned long*)((char*)self->records.data + self->selected * 0x9C + 0x94), &handle)) {
            setFirst(resolve(self->second), self->records.data[self->selected].handle98);
            setSecond(resolve(self->second), handle);
            fn_8023DE28(resolveAlternate(resolve(self->first)->child));
            fn_802073E8(self, 48,
                (MenuRecordSwitchObject*)menuRecordResolveMessage(resolve(self->second)->parent), lbl_8037AF90);
        }
    }
}
