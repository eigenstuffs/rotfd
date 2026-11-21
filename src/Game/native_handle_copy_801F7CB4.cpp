// Bounded native ABI view of the handle copy entry. Registry storage and
// virtual cleanup providers remain separately owned by their existing units.
typedef unsigned long u32;
struct NativeCopyHandle {
    union{u32 value;struct{signed int generation:8;signed int index:24;}bits;};
    int getIndex() const { return bits.index; }
};
typedef NativeCopyHandle Handle;
struct NativeCopyObjectStorage { char unknown[8]; };
struct NativeCopyObject : NativeCopyObjectStorage { virtual ~NativeCopyObject(); };
struct NativeCopyEntry { NativeCopyObject* object; u32 name; short link, references; signed char generation, flags; char padding[2]; };
struct NativeCopyNameHash { u32 value; NativeCopyNameHash(const char*); };
extern "C" { u32 fn_801F948C(void*, const char*); extern const char lbl_8037A820[1]; }
inline NativeCopyNameHash::NativeCopyNameHash(const char* name) { value = fn_801F948C(this, name); }
struct NativeCopyManagerStorage {
    int count, capacity; NativeCopyEntry* entries; u32 unknown0C, unknown10;
    int* freeIndices; u32 unknown18; int freeCount; signed char automatic; char padding[3];
};
struct NativeCopyManager : NativeCopyManagerStorage {
    virtual void slot0();
    virtual void slot1();
    virtual void detach(const void*);
    template<class T> T& field(int index, int offset) { return *(T*)((char*)entries + index * sizeof(NativeCopyEntry) + offset); }
    int valid(int index, signed char generation) {
        int valid = false;
        if (index < count && generation == field<signed char>(index, 12)) valid = true;
        return valid;
    }
    void adjust(const Handle& handle, short delta);
    void release(const Handle& handle) {
        signed char generation = handle.bits.generation;
        int index = handle.bits.index;
        if (valid(index, generation)) {
            detach((char*)field<NativeCopyObject*>(index, 0) + 4);
            field<signed char>(index, 13) = 0;
            field<short>(index, 8) = -1;
            delete field<NativeCopyObject*>(index, 0);
            field<u32>(index, 4) = NativeCopyNameHash(lbl_8037A820).value;
            field<short>(index, 10) = 0;
            ++field<signed char>(index, 12);
            if (!field<NativeCopyEntry>(index, 0).generation) ++field<NativeCopyEntry>(index, 0).generation;
            field<NativeCopyObject*>(index, 0) = 0;
            int slot = freeCount++;
            freeIndices[slot] = index;
        }
    }
};
inline void NativeCopyManager::adjust(const Handle& handle, short delta) {
    signed char generation = handle.bits.generation;
    int index = handle.getIndex();
    if (valid(index, generation)) {
        if (!(field<short>(index, 10) += delta) && automatic)
            release(handle);
    }
}
struct NativeCopyGlobals { char unknown[0x118]; NativeCopyManager* manager; };
extern "C" NativeCopyGlobals lbl_801E9D24;

extern "C" NativeCopyHandle* fn_801F7CB4(NativeCopyHandle* self, const NativeCopyHandle* other) {
    self->value = other->value;
    lbl_801E9D24.manager->adjust(*other, 1);
    return self;
}

typedef char NativeCopyHandleSize[(sizeof(NativeCopyHandle) == 4) ? 1 : -1];
typedef char NativeCopyEntrySize[(sizeof(NativeCopyEntry) == 16) ? 1 : -1];
