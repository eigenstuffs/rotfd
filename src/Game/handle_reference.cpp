// Reference-count updates and automatic release of registry records.
typedef unsigned long u32;
struct Handle { signed int generation : 8; signed int index : 24; };
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
extern "C" void fn_801F86C8(Manager* self, const Handle& handle, short delta) {
    signed char generation = handle.generation;
    int index = handle.index;
    if (self->valid(index, generation)) {
        if (!(self->field<short>(index, 10) += delta) && self->automatic)
            self->release(handle);
    }
}
