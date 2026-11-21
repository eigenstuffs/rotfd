#ifndef ROTFD_RELATED_HANDLE_FORWARD_INTERNAL_H
#define ROTFD_RELATED_HANDLE_FORWARD_INTERNAL_H
// Private views for the four related-handle forwarding methods.
typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct Object;
struct RelatedObject {
    u32 name;
    Handle identity;
    char unknown08[0x60 - 8];
    Handle related60;
    u32 unknown64;
    Handle related68, related6C;
};
struct Entry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; Entry* entries; };
struct Globals { char unknown[0x118]; Manager* manager; };
extern "C" {
extern Globals lbl_801E9D24;
signed char fn_801E48EC(Object*, const Handle*);
void fn_801FC26C(Object*, u32, Handle*, void*, float);
signed char fn_801C4968(Object*, const void*, void*, signed char);
signed char fn_801C4B7C(Object*, void*);
}
static inline Object* resolve(const Handle& handle) {
    Entry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}
#endif
