/* Erase the first handle resolving to the requested resource, release its
 * ownership, and compact both four-byte handle and value arrays. */
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
struct EraseWrappedHandle : Handle_801F7F10 { ~EraseWrappedHandle() {} };
struct EraseNestedHandle : EraseWrappedHandle { ~EraseNestedHandle() {} };
struct EraseOwnedHandle : EraseNestedHandle { ~EraseOwnedHandle() {} };
struct EraseOwner_8022C598 {
    char unknown00[0x2C];
    int count, capacity;
    EraseOwnedHandle* handles;
    int valueCount, valueCapacity;
    unsigned long* values;
};
typedef char EraseHandleSize[sizeof(EraseOwnedHandle) == 4 ? 1 : -1];
typedef char EraseEntrySize[sizeof(EraseEntry) == 16 ? 1 : -1];
extern "C" void* memcpy(void*, const void*, unsigned long);
static inline int findIndex(EraseOwner_8022C598* self,
                            const Handle_801F7F10* handle) {
    for (int i = 0; i < self->count; ++i)
        if (self->handles[i] == *handle)
            return i;
    return -1;
}

extern "C" void fn_8022C598(EraseOwner_8022C598* self,
                           const Handle_801F7F10* handle) {
    int i = findIndex(self, handle);
    if (i >= 0) {
        self->handles[i].~EraseOwnedHandle();
        EraseOwnedHandle* dest = &self->handles[i];
        int count = --self->count;
        memcpy(dest, dest + 1, (count - i) * sizeof(EraseOwnedHandle));
        unsigned long* valueDest = &self->values[i];
        int valueCount = --self->valueCount;
        memcpy(valueDest, valueDest + 1, (valueCount - i) * sizeof(unsigned long));
    }
}
