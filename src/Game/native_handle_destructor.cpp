// Native handle destruction: release its reference and optionally free storage.
typedef unsigned long u32;
extern "C" { extern char lbl_801EF5C8[]; void fn_801EF610(void*, void*); }
struct Handle_801F7F10 {
    signed int generation : 8; signed int index : 24;
    Handle_801F7F10();
    ~Handle_801F7F10();
    int getIndex() const { return index; }
    static void operator delete(void* memory) { fn_801EF610(lbl_801EF5C8, memory); }
};
typedef Handle_801F7F10 Handle;
struct ObjectStorage { char unknown[8]; };
struct Object : ObjectStorage { virtual ~Object(); };
struct Entry { Object* object; u32 name; short link, references; signed char generation, flags; char padding[2]; };
struct NameHash { u32 value; NameHash(const char*); };
extern "C" { u32 fn_801F948C(void*, const char*); extern const char lbl_8037A820[1]; }
inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
struct ManagerStorage {
    int count, capacity; Entry* entries; u32 unknown0C, unknown10;
    int* freeIndices; u32 unknown18; int freeCount; signed char automatic; char padding[3];
};
struct Manager : ManagerStorage {
    virtual void slot0();
    virtual void slot1();
    virtual void detach(const void*);
    template<class T> T& field(int index, int offset) { return *(T*)((char*)entries + index * sizeof(Entry) + offset); }
    int valid(int index, signed char generation) {
        int valid = false;
        if (index < count && generation == field<signed char>(index, 12)) valid = true;
        return valid;
    }
    void adjust(const Handle& handle, short delta);
    void release(const Handle& handle) {
        signed char generation = handle.generation;
        int index = handle.index;
        if (valid(index, generation)) {
            detach((char*)field<Object*>(index, 0) + 4);
            field<signed char>(index, 13) = 0;
            field<short>(index, 8) = -1;
            delete field<Object*>(index, 0);
            field<u32>(index, 4) = NameHash(lbl_8037A820).value;
            field<short>(index, 10) = 0;
            ++field<signed char>(index, 12);
            if (!field<Entry>(index, 0).generation) ++field<Entry>(index, 0).generation;
            field<Object*>(index, 0) = 0;
            int slot = freeCount++;
            freeIndices[slot] = index;
        }
    }
};
inline void Manager::adjust(const Handle& handle, short delta) {
    signed char generation = handle.generation;
    int index = handle.getIndex();
    if (valid(index, generation)) {
        if (!(field<short>(index, 10) += delta) && automatic)
            release(handle);
    }
}
struct Globals { char unknown[0x118]; Manager* manager; };
extern "C" Globals lbl_801E9D24;
Handle_801F7F10::~Handle_801F7F10() { lbl_801E9D24.manager->adjust(*this, -1); }
