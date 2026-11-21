#include "Game/engine_resource_selection_link.h"

typedef unsigned long Word;
struct Handle_801F7F10 {
    union { Word value; struct { signed int generation:8, index:24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ResourceSelectionActor;
struct ResourceSelectionResource;
struct ResourceSelectionActorEntry {
    ResourceSelectionActor* object;
    Word unknown04, unknown08;
    signed char generation;
    char padding[3];
};
struct ResourceSelectionActorManager {
    Word unknown00, unknown04;
    ResourceSelectionActorEntry* entries;
};
struct ResourceSelectionGlobals {
    char unknown00[0x118];
    ResourceSelectionActorManager* manager;
};
extern "C" {
extern ResourceSelectionGlobals lbl_801E9D24;
void fn_801F86C8(ResourceSelectionActorManager*, const void*, short);
void* fn_801F7EB8(const Handle_801F7F10*);
}
struct ResourceSelectionZero : Handle_801F7F10 {
    ResourceSelectionZero() { value = 0; }
    ~ResourceSelectionZero() {}
};
struct ResourceSelectionHandle : ResourceSelectionZero {
    ResourceSelectionHandle() { value = 0; }
    ~ResourceSelectionHandle() {}
    ResourceSelectionHandle& operator=(const ResourceSelectionHandle& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
};
struct ResourceSelectionResource {
    char unknown00[0x74];
    ResourceSelectionHandle linked74;
};
struct ResourceSelectionActor {
    char unknown00[0xB8];
    ResourceSelectionHandle childB8;
};
struct ResourceSelectionEntry {
    ResourceSelectionResource* object;
    Word unknown04, unknown08;
    signed char generation;
    char padding[3];
};
struct ResourceSelectionManager {
    Word unknown00, unknown04;
    ResourceSelectionEntry* entries;
};
inline ResourceSelectionActor* resolveActor(const Handle_801F7F10& h) {
    ResourceSelectionActorEntry* e = lbl_801E9D24.manager->entries + h.bits.index;
    return e->generation == h.bits.generation ? e->object : 0;
}
inline ResourceSelectionResource* resolve(const Handle_801F7F10& h) {
    ResourceSelectionEntry* e =
        ((ResourceSelectionManager*)lbl_801E9D24.manager)->entries + h.bits.index;
    return e->generation == h.bits.generation ? e->object : 0;
}
struct ResourceSelectionName { Word value; };
struct ResourceSelectionRecord {
    Word name;
    ResourceSelectionHandle first, second;
};
struct ResourceSelectionSlots {
    int count, capacity;
    ResourceSelectionRecord* items;
};
struct ResourceSelectionOwner {
    char unknown00[0x1C];
    ResourceSelectionSlots slots;
};
extern "C" {
ResourceSelectionHandle fn_802631B0(ResourceSelectionOwner*, const ResourceSelectionName*);
int fn_8026276C(ResourceSelectionSlots*);
void fn_80261C0C(ResourceSelectionRecord*,
    const ResourceSelectionHandle*, const ResourceSelectionHandle*);
}
extern "C" unsigned char fn_8026248C(ResourceSelectionOwner* self,
    const ResourceSelectionName* first, const ResourceSelectionName* second) {
    unsigned char result = 255;
    ResourceSelectionHandle current;
    ResourceSelectionHandle a;
    ResourceSelectionHandle b;
    current = fn_802631B0(self, first);
    if (fn_801F7EB8(&current)) {
        a = resolve(resolveActor(current)->childB8)->linked74;
        current = fn_802631B0(self, second);
        if (fn_801F7EB8(&current)) {
            b = resolve(resolveActor(current)->childB8)->linked74;
            if (fn_801F7EB8(&b) && fn_801F7EB8(&a)) {
                result = fn_8026276C(&self->slots);
                fn_80261C0C(&self->slots.items[result], &b, &a);
                self->slots.items[result].name = first->value;
            }
        }
    }
    return result;
}
