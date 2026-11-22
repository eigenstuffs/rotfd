#include "Game/engine_owner_contact_events.h"

static inline ContactObject* resolve(const Handle_801F7F10& handle) {
    ContactEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    return entry->generation == handle.bits.generation ? entry->object : 0;
}
static inline ContactObject* resolveBytes(const Handle_801F7F10& handle) {
    struct ByteManager { int count, capacity; char* entries; };
    ContactEntry* entry = (ContactEntry*)
        (((ByteManager*)lbl_801E9D24.manager)->entries + handle.bits.index * 16);
    return entry->generation == handle.bits.generation ? entry->object : 0;
}
static inline ContactWord resolveMessage(const Handle_801F7F10& handle) {
    int index = handle.bits.index;
    ContactManager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == handle.bits.generation) return (ContactWord)manager->entries[index].object;
    return 0;
}

extern "C" void slot64__12ObjectMove_ZFv(ContactOwner* self, ContactObject* subject,
                           const void* position, const void* hit, ContactFlags flags) {
    ContactObject* owner = resolve(self->resource);
    if (flags & 0x800000000000ULL) {
        ContactObject* other = resolveBytes(subject->related);
        if (other && (other->flags & 0x400000ULL)) {
            ContactObject* active = resolveBytes(other->active);
            if (active) {
                if (self->state & 0x400000000000ULL) {
                    active->state |= 0x800000000000ULL;
                    self->state |= 0x1000000000000ULL;
                }
                if (active->state & 0x400000000000ULL) {
                    self->state |= 0x800000000000ULL;
                    active->state |= 0x1000000000000ULL;
                }
            }
            int event;
            if (owner->queryFirst(&event)) {
                const Handle_801F7F10& original = other->self;
                fn_802073E8(owner, event, (ContactObject*)resolveMessage(ContactCopy(original)), lbl_8037B074);
            }
            if (other->querySecond(&event)) {
                const Handle_801F7F10& original = owner->self;
                fn_802073E8(other, event, (ContactObject*)resolveMessage(ContactCopy(original)), lbl_8037B074);
            }
            {
                const Handle_801F7F10& original = owner->self;
                fn_802073E8(other, 57, (ContactObject*)resolveMessage(ContactCopy(original)), lbl_8037B074);
            }
            if ((subject->nodeFlags & 0x100400) == 0x400) {
                const Handle_801F7F10& original = owner->self;
                fn_802073E8(other, 62, (ContactObject*)resolveMessage(ContactCopy(original)), lbl_8037B074);
            }
        } else {
            fn_802073E8(owner, 57, owner, lbl_8037B074);
        }
    } else if (!(flags & 8)) {
        fn_802073E8(owner, 58, owner, lbl_8037B074);
    }
}
