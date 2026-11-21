// Reconstructed from GSQE78. Original class names remain unestablished.
typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct Object;
struct HandleList { int count, capacity; Handle* data; };
struct Group { char unknown[0x14]; HandleList entries; };
struct ResourceEntry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Globals { char unknown[0x118]; Manager* manager; };
extern "C" Globals lbl_801E9D24;

static inline Object* get(Manager* manager, const Handle& handle) {
    ResourceEntry* entry = manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}
static inline bool equal(const Handle& a, const Handle& b) {
    Manager* manager = lbl_801E9D24.manager;
    Object* const object = get(manager, b);
    return object == get(manager, a);
}
extern "C" int fn_801FF18C(Group* self, Handle* target) {
    for (int i = 0; i < self->entries.count; ++i) {
        if (equal(self->entries.data[i], *target))
            return i;
    }
    return -1;
}
