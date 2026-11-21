// Remaining capacity among groups with an assigned range.
#include "group_runtime_internal.h"
inline Object* capacityObject(Manager* manager, const Handle& h) {
    ResourceEntry* entry = manager->entries + h.bits.index;
    if (entry->generation == h.bits.generation) return entry->object;
    return 0;
}
extern "C" int fn_801FF9C8(Group* self) {
    Manager* manager = lbl_801E9D24.manager;
    int available = 4;
    for (int i = 0; i < self->entries.count; ++i) {
        Object* object = capacityObject(manager, self->entries.data[i]);
        if (object && object->state >= 0)
            available -= object->current;
    }
    return available;
}
