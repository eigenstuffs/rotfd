/* fn_8026B768: insert a handle into a sparse handle table, propagate the
   returned slot index to the resolved owner's children (fn_8023FBE4), then
   clear two state words on the object the new slot resolves to. */
extern "C" {
extern struct { char unknown00[0x118]; void* manager; } lbl_801E9D24;
void fn_801F86C8(void*, const void*, int);
unsigned long fn_801F7EB8(const void*);
}
struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct SparseReleaseZero1 : Handle_801F7F10 { SparseReleaseZero1() { value = 0; } };
struct SparseReleaseHandle : SparseReleaseZero1 {
    SparseReleaseHandle(const SparseReleaseHandle& input) {
        value = input.value;
        fn_801F86C8(lbl_801E9D24.manager, &input, 1);
    }
};
struct SparseReleaseEntry {
    char* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct SparseReleaseManager { int count, capacity; SparseReleaseEntry* entries; };
inline char* resolveSparseRelease(const Handle_801F7F10& handle) {
    int index = handle.bits.index;
    SparseReleaseManager* manager = (SparseReleaseManager*)lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == handle.bits.generation) return manager->entries[index].object;
    return 0;
}
struct SparseReleaseTarget { char unknown0000[0xD9F8]; long firstState, secondState; };
struct SparseReleaseArray { int count, capacity; SparseReleaseHandle* data; };
struct SparseReleaseNode;
extern "C" void fn_8023FBE4(SparseReleaseNode*, int, signed char);
struct SparseReleaseOwner { char unknown00[0xC]; SparseReleaseArray children;
    void setScene(int index) {
        for (int i = 0; i < children.count; i++)
            fn_8023FBE4((SparseReleaseNode*)resolveSparseRelease(children.data[i]), index, 0);
    }
};
struct SparseReleaseSelf {
    int count, capacity;
    SparseReleaseHandle* items;
    SparseReleaseHandle& operator[](int i) { return items[i]; }
};
extern "C" int fn_8026B908(SparseReleaseSelf*, const SparseReleaseHandle&);

extern "C" void fn_8026B768(SparseReleaseSelf* self, const SparseReleaseHandle& input)
{
    int index = fn_8026B908(self, SparseReleaseHandle(input));
    ((SparseReleaseOwner*)resolveSparseRelease(input))->setScene(index);
    if (fn_801F7EB8(&(*self)[index])) {
        SparseReleaseTarget* target = (SparseReleaseTarget*)resolveSparseRelease((*self)[index]);
        target->firstState = 0;
        target->secondState = 0;
    }
}
