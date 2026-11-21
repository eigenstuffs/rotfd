// Recovered from GSQE78: nested-handle status queries.
// Names describe observed roles; original class and method names are unknown.
typedef unsigned long u32;
struct Handle {
    union { u32 value; struct { signed int generation:8; signed int index:24; } bits; };
};
struct HandleList { int count, capacity; Handle* data; };
struct Object {
    char unknown00[0x18];
    signed char active;
    char unknown19[0x6C-0x19];
    Handle related;
    signed char getActive() const { return active; }
};
struct Hierarchy { char unknown00[0xD0]; HandleList entries; int count, width, offset; };
struct ResourceEntry { Object* object; u32 unused[2]; signed char generation; char padding[3]; };
struct Manager { u32 unused[2]; ResourceEntry* entries; };
// The related lookup retains a separate typed load of the manager table.
struct RelatedManagerView { u32 unused[2]; ResourceEntry* entries; };
struct Globals { char unknown00[0x118]; Manager* manager; };
extern "C" Globals lbl_801E9D24;
extern "C" u32 fn_801F7EB8(Handle*);
static inline Object* resolve(const Handle& h) {
    ResourceEntry* e = lbl_801E9D24.manager->entries + h.bits.index;
    return e->generation == h.bits.generation ? e->object : 0;
}
static inline Object* resolveRelated(const Handle& h) {
    ResourceEntry* e = ((RelatedManagerView*)lbl_801E9D24.manager)->entries + h.bits.index;
    return e->generation == h.bits.generation ? e->object : 0;
}
static inline signed char anyActive(Hierarchy* self) {
    for (int i=0; i<self->entries.count; ++i)
        if (fn_801F7EB8(&self->entries.data[i]))
            if (resolveRelated(resolve(self->entries.data[i])->related)->active)
                return 1;
    return 0;
}
extern "C" int fn_80206868(Hierarchy* self, int index) {
    if (index < 0) {
        for (int i=0; i<self->entries.count; ++i)
            if (fn_801F7EB8(&self->entries.data[i]))
                if (resolveRelated(resolve(self->entries.data[i])->related)->active)
                    return 1;
    } else {
        return resolveRelated(resolve(self->entries.data[index])->related)->getActive();
    }
    return 0;
}
extern "C" signed char fn_80206A20(Hierarchy* self) {
    return !anyActive(self);
}
