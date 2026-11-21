#ifndef ROTFD_HANDLE_FROM_TOKEN_INTERNAL_H
#define ROTFD_HANDLE_FROM_TOKEN_INTERNAL_H
// Private registry layouts and native owned-handle copy construction.
typedef unsigned long u32;
struct Handle { union {u32 value; struct {signed int generation : 8; signed int index : 24;} bits;}; int getIndex() const{return bits.index;} };
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
        signed char generation = handle.bits.generation;
        int index = handle.bits.index;
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
    void retain(const Handle& handle) {
        signed char generation = handle.bits.generation;
        int index = handle.getIndex();
        if (valid(index, generation)) {
            if (!++field<short>(index, 10) && automatic) release(handle);
        }
    }

};

struct Globals {char unknown[0x118];Manager* manager;};
extern "C" Globals lbl_801E9D24;
struct Handle_801F7F10 {
 Handle token;
 Handle_801F7F10(){token.value=0;}
 Handle_801F7F10(const Handle_801F7F10& source){token=source.token;lbl_801E9D24.manager->retain(source.token);}
 ~Handle_801F7F10();
};

#endif
