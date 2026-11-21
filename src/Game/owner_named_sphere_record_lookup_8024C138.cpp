/* Find the named record for a resolved handle, copy its four float values,
 * and report the first owner handle with the same resolved identity. */
struct HandleIndex {
    int value;
    HandleIndex(int v) : value(v) {}
    operator int() const { return value; }
};
struct LookupName {
    unsigned long value;
    bool operator==(const LookupName& other) const {
        return value == other.value;
    }
};
struct LookupHandle {
    signed int generation : 8;
    signed int index : 24;
};
struct LookupObject { void* identity; };
struct LookupEntry {
    LookupObject* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    bool matchesGeneration(signed char tag) const {
        return generation == tag;
    }
};
struct LookupManager { char unknown00[8]; LookupEntry* entries; };
struct LookupGlobals { char unknown00[0x118]; LookupManager* manager; };
struct LookupValue {
    float x, y, z, w;
    LookupValue& operator=(const LookupValue& value) {
        x = value.x; y = value.y; z = value.z; w = value.w;
        return *this;
    }
};
struct LookupRecord {
    LookupName key;
    LookupHandle handle;
    LookupValue value;
    void copyValue(LookupValue& out) const {
        out.x = value.x;
        out.y = value.y;
        out.z = value.z;
        out.w = value.w;
    }
};
struct LookupOwner {
    char unknown00[0x20];
    int count, capacity;
    LookupHandle* handles;
    char unknown2C[0x2C];
    int recordCount, recordCapacity;
    LookupRecord* records;
};
struct LookupOutput { LookupValue value; int index; };
extern "C" {
extern LookupGlobals lbl_801E9D24;
void* fn_801F7EB8(const void*);
}
typedef char LookupNameSize[sizeof(LookupName) == 4 ? 1 : -1];
typedef char LookupHandleSize[sizeof(LookupHandle) == 4 ? 1 : -1];
typedef char LookupEntrySize[sizeof(LookupEntry) == 16 ? 1 : -1];
typedef char LookupRecordSize[sizeof(LookupRecord) == 24 ? 1 : -1];

static inline LookupObject* resolveLookup(const LookupHandle& handle) {
    LookupManager* manager = lbl_801E9D24.manager;
    const HandleIndex index(handle.index);
    signed char tag = handle.generation;
    if (manager->entries[index].matchesGeneration(tag))
        return manager->entries[index].object;
    return 0;
}
static inline int findLookupIdentity(LookupOwner* self, void* const& identity) {
    for (int i = 0; i < self->count; ++i) {
        if (fn_801F7EB8(&self->handles[i]) &&
            resolveLookup(self->handles[i])->identity == identity)
            return i;
    }
    return -1;
}
extern "C" signed char fn_8024C138(LookupOwner* self, const LookupName& key,
                                   const LookupHandle& handle,
                                   LookupOutput* output) {
    for (int i = 0; i < self->recordCount; ++i) {
        if (self->records[i].key == key &&
            resolveLookup(self->records[i].handle) == resolveLookup(handle)) {
            self->records[i].copyValue(output->value);
            output->index = findLookupIdentity(
                self, resolveLookup(self->records[i].handle)->identity);
            return 1;
        }
    }
    return 0;
}
