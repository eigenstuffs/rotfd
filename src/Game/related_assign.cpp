// Reconstructed related-object assignment and replacement methods.
typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct Object;
struct HandleList { int count, capacity; Handle* data; };
struct Holder {
    char unknown[0x9C];
    HandleList assigned;
    char unknownA8[0x18];
    Handle related;
};
struct ResourceEntry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Globals { char unknown[0x118]; Manager* manager; };
extern "C" {
extern Globals lbl_801E9D24;
void fn_801F86C8(Manager*, Handle*, short);
void fn_8022C6FC(Object*, Handle*, u32);
void fn_8022BE34(Object*, Handle*);
}
static inline Object* resolve(const Handle& handle) {
    ResourceEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}
static inline void assign(Handle* dest, Handle* source) {
    fn_801F86C8(lbl_801E9D24.manager, dest, -1);
    dest->value = source->value;
    fn_801F86C8(lbl_801E9D24.manager, source, 1);
}
extern "C" void fn_802003A4(Holder* self, Handle* add, Handle* remove) {
    fn_8022C6FC(resolve(self->related), add, 4);
    fn_8022BE34(resolve(self->related), remove);
}
extern "C" void fn_802002A4(Holder* self, int index, Handle* remove, Handle* add) {
    assign(&self->assigned.data[index], add);
    fn_8022C6FC(resolve(self->related), add, 1);
    fn_8022BE34(resolve(self->related), remove);
}
