// Recovered base-object methods and native virtual table.
typedef unsigned long u32;
struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10(int index, signed char generation) {
        bits.index = index;
        bits.generation = generation;
    }
};
struct Entry {
    void* object;
    u32 name, unused;
    signed char generation;
    char pad[3];
};
struct Manager { int count, capacity; Entry* entries; };
struct Globals {
    char unused[0x118];
    Manager* manager;
    char unknown11C[8];
    void* world;
};
extern "C" {
extern Globals lbl_801E9D24;
extern char lbl_801EF5C8[];
void fn_801B41F4(Manager*, void*, u32);
signed char fn_801F8C88(Manager*, const void*);
void fn_801F8CF0(Manager*, const void*, signed char);
void fn_802602B8(void*);
void fn_8025EAB0(void*, u32, const void*, float);
void fn_801F7914(void*, const void*);
void fn_801EF610(void*, void*);
// The recovered base prefix keeps identity as raw four-byte handle storage.
// These declarations expose the verified native initialization/cleanup ABI.
void* __ct__15Handle_801F7F10Fv(void*);
void* __dt__15Handle_801F7F10Fv(void*, short);
}
struct RootStorage_80207414 { u32 unknown0, identity; };
struct BaseObject_Z : RootStorage_80207414 {
    BaseObject_Z();
    virtual ~BaseObject_Z();
    virtual void slot0C(u32);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
    static void operator delete(void* memory) {
        fn_801EF610(lbl_801EF5C8, memory);
    }
};
struct EmptyIdentity {
    Handle_801F7F10 value;
    EmptyIdentity() : value(0, 0) {}
};

BaseObject_Z::BaseObject_Z() {
    unknown0 = 0;
    __ct__15Handle_801F7F10Fv(&identity);
}
BaseObject_Z::~BaseObject_Z() {
    {
        EmptyIdentity empty;
        fn_801F7914(&identity, &empty.value);
    }
    __dt__15Handle_801F7F10Fv(&identity, -1);
}
extern "C" void fn_802073E8(BaseObject_Z* self, u32 value, void* target, float time) {
    fn_8025EAB0(target, value, &self->identity, time);
}
extern "C" void fn_802073BC() {
    fn_802602B8(lbl_801E9D24.world);
}
signed char BaseObject_Z::slot1C() {
    if (fn_801F8C88(lbl_801E9D24.manager, &identity))
        return false;
    fn_801F8CF0(lbl_801E9D24.manager, &identity, 1);
    return true;
}
extern "C" void fn_802072D4(BaseObject_Z* self, const u32* name, signed char update) {
    self->unknown0 = *name;
    if (!update)
        return;
    const Handle_801F7F10& handle = *(const Handle_801F7F10*)&self->identity;
    signed char generation = handle.bits.generation;
    Manager* manager = lbl_801E9D24.manager;
    int index = handle.bits.index;
    int valid = false;
    // The original indexes the generation/name fields within 16-byte records.
    if (index < manager->count &&
        generation == *((signed char*)manager->entries + index * 16 + 12))
        valid = true;
    if (!valid)
        return;
    *(u32*)((char*)manager->entries + index * 16 + 4) = *name;
}
void BaseObject_Z::slot0C(u32 value) {
    fn_801B41F4(lbl_801E9D24.manager, this, value);
}
