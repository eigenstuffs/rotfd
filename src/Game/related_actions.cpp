// Reconstructed related-object forwarding ABI from GSQE78.
typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct Object;
struct Holder { char unknown[0xC0]; Handle related; };
struct ResourceEntry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Globals { char unknown[0x118]; Manager* manager; };
extern "C" Globals lbl_801E9D24;
static inline Object* resolve(const Handle& handle) {
    ResourceEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}
extern "C" {
void fn_8022B9F8(Object*, Handle*);
void fn_8022BB30(Object*, Handle*);
void fn_8022BCFC(Object*, Handle*);
void fn_8022BE34(Object*, Handle*);
void fn_8022B6FC(Object*, Handle*);
void fn_8022B830(Object*, Handle*);
void fn_8022C598(Object*, Handle*);
void fn_8022C6FC(Object*, Handle*, u32);
u32 fn_8022B5B0(Object*, const u32*, Handle*);
}

extern "C" u32 fn_8020023C(Holder* self, const u32* name, Handle* out) {
    return fn_8022B5B0(resolve(self->related), name, out);
}
extern "C" void fn_802001D4(Holder* self, Handle* handle, u32 flags) {
    fn_8022C6FC(resolve(self->related), handle, flags);
}
extern "C" void fn_8020016C(Holder* self, Handle* handle) {
    fn_8022C598(resolve(self->related), handle);
}
extern "C" void fn_80200104(Holder* self, Handle* handle) {
    fn_8022B830(resolve(self->related), handle);
}
extern "C" void fn_8020009C(Holder* self, Handle* handle) {
    fn_8022B6FC(resolve(self->related), handle);
}
extern "C" void fn_80200034(Holder* self, Handle* handle) {
    fn_8022BE34(resolve(self->related), handle);
}
extern "C" void fn_801FFFCC(Holder* self, Handle* handle) {
    fn_8022BCFC(resolve(self->related), handle);
}
extern "C" void fn_801FFF64(Holder* self, Handle* handle) {
    fn_8022BB30(resolve(self->related), handle);
}
extern "C" void fn_801FFEFC(Holder* self, Handle* handle) {
    fn_8022B9F8(resolve(self->related), handle);
}
