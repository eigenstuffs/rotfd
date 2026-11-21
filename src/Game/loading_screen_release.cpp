// Remove an active LoadingScreen resource from its renderer collection.
typedef unsigned long u32;
struct Registry;
struct Resource;
struct Globals {
    char unknown[0x114];
    char* renderer;
    Registry* registry;
};
extern "C" {
extern Globals lbl_801E9D24;
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
void fn_801F86C8(Registry*, const void*, int);
}
struct Handle_801F7F10 {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
    Resource* resolve() const;
    static void operator delete(void* p) throw() {
        fn_801EF610(lbl_801EF5C8, p);
    }
};
struct Handle_80020478 : Handle_801F7F10 {
    Handle_80020478() { value = 0; }
    ~Handle_80020478() {}
};
struct Handle_80021BCC : Handle_80020478 {
    Handle_80021BCC() { value = 0; }
    ~Handle_80021BCC() {}
};
struct Handle_8002F6B0 : Handle_80021BCC {
    Handle_8002F6B0(const Handle_801F7F10& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.registry, &source, 1);
    }
    ~Handle_8002F6B0() {}
};
struct Entry {
    Resource* object;
    u32 unknown[2];
    signed char generation;
    char padding[3];
};
struct Registry { int size, capacity; Entry* entries; };
inline Resource* Handle_801F7F10::resolve() const {
    Entry* entry = &lbl_801E9D24.registry->entries[bits.index];
    return entry->generation == bits.generation ? entry->object : 0;
}
struct LoadingScreenState {
    char unknown[0x50];
    Handle_801F7F10 resource;
};
extern "C" {
Resource* fn_801F7EB8(const Handle_801F7F10*);
void fn_802535D8(LoadingScreenState*);
void fn_802139D8(Resource*);
void fn_801E1F3C(void*, const Handle_8002F6B0&);

void fn_800C5FB4(LoadingScreenState* self) {
    fn_802535D8(self);
    if (fn_801F7EB8(&self->resource)) {
        fn_802139D8(self->resource.resolve());
    }
    fn_801E1F3C(lbl_801E9D24.renderer + 0x1C8,
               Handle_8002F6B0(self->resource));
}
}
