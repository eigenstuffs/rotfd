/* Erase the first handle resolving to the requested resource, release its
 * ownership, and compact the remaining four-byte handle elements. */
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
struct EraseOwnedHandle : EraseWrappedHandle { ~EraseOwnedHandle() {} };
struct EraseOwner_8022B6FC {
    char unknown00[0x54];
    int count, capacity;
    EraseOwnedHandle* handles;
};
typedef char EraseHandleSize[sizeof(EraseOwnedHandle) == 4 ? 1 : -1];
typedef char EraseEntrySize[sizeof(EraseEntry) == 16 ? 1 : -1];
extern "C" void* memcpy(void*, const void*, unsigned long);
extern "C" void fn_8022B6FC(EraseOwner_8022B6FC* self,
                            const Handle_801F7F10* handle) {
    int i;
    for (i = 0; i < self->count; ++i)
        if (self->handles[i] == *handle)
            break;
    if (i != self->count) {
        self->handles[i].~EraseOwnedHandle();
        EraseOwnedHandle* destination = &self->handles[i];
        int count = --self->count;
        memcpy(destination, destination + 1,
               (count - i) * sizeof(EraseOwnedHandle));
    }
}
