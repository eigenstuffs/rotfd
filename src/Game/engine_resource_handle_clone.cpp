#include "Game/engine_resource_handle_clone.h"

typedef char ResourceCloneOwnerSize[(sizeof(ResourceCloneOwner) == 0x2C) ? 1 : -1];
typedef char ResourceCloneDataSize[(sizeof(ResourceCloneData) == 0x2C) ? 1 : -1];
typedef char ResourceCloneParentSize[(sizeof(ResourceCloneParent) == 0xCC) ? 1 : -1];
typedef char ResourceCloneEntrySize[(sizeof(ResourceCloneEntry) == 16) ? 1 : -1];
typedef char ResourceCloneBaseEntrySize[(sizeof(ResourceCloneBaseEntry) == 16) ? 1 : -1];

static inline void assignResourceClone(Handle_801F7F10& to, const Handle_801F7F10& from) {
    fn_801F86C8(lbl_801E9D24.manager, &to, -1);
    to.value = from.value;
    fn_801F86C8(lbl_801E9D24.manager, &from, 1);
}

static inline ResourceCloneElement* resolveResourceClone(const Handle_801F7F10& handle) {
    ResourceCloneEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    return entry->generation == handle.bits.generation ? entry->object : 0;
}

static inline ResourceCloneElementPrefix* resolveResourceCloneBase(const Handle_801F7F10& handle) {
    ResourceCloneBaseManager* manager = (ResourceCloneBaseManager*)lbl_801E9D24.manager;
    ResourceCloneBaseEntry* entry = &manager->entries[handle.bits.index];
    return entry->generation == handle.bits.generation ? entry->object : 0;
}

static inline ResourceCloneParent* resourceCloneParent(Handle_801F7F10& handle) {
    return (ResourceCloneParent*)resolveResourceClone(ResourceCloneCopy2(handle));
}

extern "C" void fn_80245B8C(ResourceCloneOwner* self, Handle_801F7F10& target, Handle_801F7F10& parent) {
    assignResourceClone(target, ResourceCloneCopy1(fn_801B550C(lbl_801E9D24.manager,
        ResourceCloneName(lbl_8037B3D4), self->name)));
    ResourceCloneData* object = (ResourceCloneData*)resolveResourceClone(ResourceCloneCopy2(target));
    ResourceCloneData* data = (ResourceCloneData*)resolveResourceClone(target);
    data->values[0] = self->values[0];
    data->values[1] = self->values[1];
    data->values[2] = self->values[2];
    data->values[3] = self->values[3];
    object->array.resize(self->array.count);
    ResourceCloneParent* owner = resourceCloneParent(parent);
    if (fn_801F7EB8(self->array.items))
        resolveResourceClone(self->array.items[0])->slot30(object->array.items[0], owner->children[0]);
    for (int i = 1; i < self->array.count; ++i) {
        const Handle_801F7F10& currentHandle = self->array.items[i];
        const Handle_801F7F10& previousHandle = self->array.items[i - 1];
        ResourceCloneElement* current = resolveResourceClone(currentHandle);
        ResourceCloneElementPrefix* previous = resolveResourceCloneBase(previousHandle);
        if (current == previous)
            assignResourceClone(object->array.items[i], object->array.items[i - 1]);
        else if (fn_801F7EB8(&self->array.items[i]))
            resolveResourceClone(self->array.items[i])->slot30(object->array.items[i], owner->children[i]);
    }
}
