typedef unsigned int u32;

struct HandleIndex {
    int value;
    HandleIndex(int v) : value(v) {}
    operator int() const { return value; }
};
struct HandleBits { signed int generation : 8; signed int index : 24; };
struct RegistryEntry {
    void* object;
    u32 key;
    char unknown08[4];
    signed char generation;
    char unknown0D[3];
};
struct HandleManager { int count, capacity; RegistryEntry* entries; };
struct Globals {
    char unknown00[0x118];
    HandleManager* manager;
    char unknown11C[0x28];
    void* primary;
    char unknown148[0x10];
    void* secondary;
};
struct Owner {
    u32 unknown00;
    HandleBits handle;
    char unknown08[0x78];
    int count, capacity;
    HandleBits* handles;
};
extern "C" {
extern Globals lbl_801E9D24;
void fn_801B3E54(HandleManager*, void*);
signed char fn_801F5F28(void*, Owner*, const u32*, u32*, int);
void fn_801F6710(void*, void*, const u32*);
}
inline u32 registryKey(const HandleBits& handle) {
    HandleManager* manager = lbl_801E9D24.manager;
    const HandleIndex index(handle.index);
    signed char generation = handle.generation;
    int valid = 0;
    if (index < manager->count &&
        generation == ((signed char*)manager->entries)[index * sizeof(RegistryEntry) + 12])
        valid = 1;
    return valid ? *(u32*)((char*)manager->entries + index * sizeof(RegistryEntry) + 4) : 0;
}
extern "C" void fn_801D3DD0(Owner* self) {
    for (int i = 0; i < self->count; ++i)
        fn_801B3E54(lbl_801E9D24.manager, &self->handles[i]);
    u32 key = registryKey(self->handle);
    u32 result;
    if (fn_801F5F28(lbl_801E9D24.primary, self, &key, &result, 0)) {
        fn_801F6710(lbl_801E9D24.primary, self, &key);
        fn_801F6710(lbl_801E9D24.secondary, self, &key);
    }
}
