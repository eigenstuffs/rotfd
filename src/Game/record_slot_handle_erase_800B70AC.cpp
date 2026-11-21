// Remove the first handle matching `handle` from slot `slot` of every record's
// handle-array table (record service). The two casts keep the original's
// separate (non-CSE'd) address computations for the count and erase paths.
struct Resource;
struct HandleIndex {
    int value;
    HandleIndex(int v) : value(v) {}
    operator int() const { return value; }
};
struct EraseEntry {
    Resource* object;
    unsigned long unknown04[2];
    signed char generation;
    char unknown0D[3];
    bool matchesGeneration(signed char tag) const {
        return generation == tag;
    }
};
struct EraseManager { int count, capacity; EraseEntry* entries; };
struct EraseGlobals {
    char unknown00[0x118];
    EraseManager* manager;
};
extern "C" EraseGlobals lbl_801E9D24;
struct Handle_801F7F10 {
    signed int generation : 8;
    signed int index : 24;
    ~Handle_801F7F10();
    Resource* get(EraseManager* manager) const {
        const HandleIndex slot(index);
        signed char tag = generation;
        if (manager->entries[slot].matchesGeneration(tag))
            return manager->entries[slot].object;
        return 0;
    }
    bool operator==(const Handle_801F7F10& handle) const {
        EraseManager* manager = lbl_801E9D24.manager;
        return get(manager) == handle.get(manager);
    }
};
struct WrappedHandle : Handle_801F7F10 { ~WrappedHandle() {} };
extern "C" void* memcpy(void*, const void*, unsigned long);
struct HandleArray {
    int count, capacity;
    WrappedHandle* data;
    void remove(int index) {
        data[index].~WrappedHandle();
        WrappedHandle* dest = &data[index];
        int n = --count;
        memcpy(dest, dest + 1, (n - index) * sizeof(WrappedHandle));
    }
};
struct Record { char unknown00[8]; HandleArray* arrays; };
struct Owner { char unknown00[0x20]; int count, capacity; Record** data; };

extern "C" void fn_800B70AC(Owner* self, const Handle_801F7F10* handle, int slot) {
    int i = 0;
    int count = self->count;
    for (; i < count; i++) {
        for (int j = 0; j < *(int*)&self->data[i]->arrays[slot]; j++) {
            if (self->data[i]->arrays[slot].data[j] == *handle) {
                ((Record**)(unsigned long)self->data)[i]->arrays[slot].remove(j);
                break;
            }
        }
    }
}
