// Reconstructed from GSQE78's object-list queries and selection controls.
// Names identify observed roles; the original class names remain unknown.
typedef unsigned long u32;

struct Handle {
    union {
        u32 value;
        struct {
            signed int generation : 8;
            signed int index : 24;
        } bits;
    };
};

struct HandleList {
    int count;
    int capacity;
    Handle* data;
};

struct Object {
    char unknown[0xC];
    Handle related;
    char unknown10[0xDC - 0x10];
    int maximum;
    int current;
};

struct Group {
    char unknown[0x14];
    HandleList entries;
};

struct ResourceEntry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};

struct Manager {
    u32 unused[2];
    ResourceEntry* entries;
};

// The comparison retains a second typed access path to the same manager.
// Its separate table load is present in both original query routines.
struct RelatedManagerView {
    u32 unused[2];
    ResourceEntry* entries;
};

struct Globals {
    char unknown[0x118];
    Manager* manager;
};

extern "C" {
extern Globals lbl_801E9D24;
u32 fn_801F7EB8(Handle*);
void fn_801FEE10(Group*, int);
void fn_801FEF6C(Group*, int);
void fn_80201C14(Object*);
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

static inline bool equal(const Handle& a, const Handle& b) {
    Object* const object = resolve(b);
    return object == resolveRelated(a);
}

extern "C" void fn_801FEDA0(Group* self, int index) {
    fn_80201C14(resolve(self->entries.data[index]));
}

extern "C" void fn_801FED04(Group* self, int index) {
    fn_801FEE10(self, index);
    resolve(self->entries.data[index])->current = 1;
    fn_801FEF6C(self, index);
}

extern "C" void fn_801FEC4C(Group* self, int index, int value) {
    fn_801FEE10(self, index);
    Object* object = resolve(self->entries.data[index]);
    if (value < 0)
        object->current = object->maximum;
    else
        object->current = value;
    fn_801FEF6C(self, index);
}

extern "C" int fn_801FEADC(Group* self, Handle* target, int minimum, int* out) {
    if (!fn_801F7EB8(target))
        return 0;
    {
        for (int i = 0; i < self->entries.count; ++i) {
            Object* object = resolve(self->entries.data[i]);
            if (object && fn_801F7EB8(&object->related)
                && equal(*target, object->related) && object->maximum >= minimum) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}

extern "C" int fn_801FE99C(Group* self, Handle* target) {
    for (int i = 0; i < self->entries.count; ++i) {
        Object* object = resolve(self->entries.data[i]);
        if (object && fn_801F7EB8(&object->related)
            && equal(*target, object->related))
            return i;
    }
    return -1;
}
