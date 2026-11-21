// Reconstructed from GSQE78. Structure names describe observed storage roles.
typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct Hierarchy { char unknown[0xC]; Handle related; };
struct Object { char unknown[0x58]; Handle owner; };
struct ResourceEntry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct RelatedManagerView { u32 unused[2]; ResourceEntry* entries; };
struct Globals { char unknown[0x118]; Manager* manager; };
extern "C" {
extern Globals lbl_801E9D24;
void fn_80240120(Object*, int);
void fn_80269FE0(Object*);
}
static inline Object* resolve(const Handle& handle) {
    ResourceEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}
static inline Object* resolveRelated(const Handle& handle) {
    ResourceEntry* entry = ((RelatedManagerView*)lbl_801E9D24.manager)->entries
                           + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}
extern "C" void fn_801FD3EC(Hierarchy* self, Handle* target) {
    fn_80240120(resolveRelated(resolve(*target)->owner), 0);
    fn_80269FE0(resolve(self->related));
}
