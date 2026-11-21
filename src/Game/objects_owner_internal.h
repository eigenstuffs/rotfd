#ifndef GAME_OBJECTS_OWNER_INTERNAL_H
#define GAME_OBJECTS_OWNER_INTERNAL_H

typedef unsigned long u32;
struct Activable_Z;
struct OwnerList;
struct Entry {
    Activable_Z* object;
    u32 unknown[2];
    signed char generation;
    char pad[3];
    signed char getGeneration() const { return generation; }
};
struct Manager { int count, capacity; Entry* entries; };
struct Cache900_802F149C;struct Cache10_802F1490;struct PlatformResource;struct PlatformPool_80281EA4;struct PlatformItem_802859A8;
struct Globals {
    char unknown0[0x118];
    Manager* manager;
    char unknown11C[0x1C];
    OwnerList* list;
    char unknown13C[0x1C];void*allocation;char unknown15C[0x1C];
    Cache900_802F149C*cache900;Cache10_802F1490*cache10;PlatformResource*resource;PlatformPool_80281EA4*pool;void*unknown188;PlatformItem_802859A8*item;
};
extern "C" {
extern Globals lbl_801E9D24;
extern char lbl_801EF5C8[];
void fn_801F86C8(Manager*, const void*, short);
Activable_Z* fn_801F7EB8(const void*);
void fn_80212AA0(OwnerList*, const void*);
void fn_801EF610(void*, void*);
void fn_80213A18(Activable_Z*);
}
struct Handle_801F7F10 {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct IdentityHandle : Handle_801F7F10 {
    IdentityHandle(const Handle_801F7F10& h) {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
};
struct OwnerHandle : Handle_801F7F10 {
    OwnerHandle() { value = 0; }
    OwnerHandle(const IdentityHandle& h) {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    OwnerHandle& operator=(const OwnerHandle& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
    Activable_Z* get() const {
        int index = bits.index;
        Manager* m = lbl_801E9D24.manager;
        int generation = m->entries[index].getGeneration();
        return generation == bits.generation ? m->entries[index].object : 0;
    }
};
struct RootStorage_80207414 { u32 unknown0; Handle_801F7F10 identity; };
struct BaseObject_Z : RootStorage_80207414 {
    BaseObject_Z();
    virtual ~BaseObject_Z();
    virtual void slot0C(u32);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
    const Handle_801F7F10& getIdentity() const { return identity; }
};
struct Activable_Z : BaseObject_Z {
    OwnerHandle prev, next;
    u32 field14;
    signed char field18;
    char pad19[3];
    Activable_Z();
    virtual ~Activable_Z();
    virtual void slot18();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    static void operator delete(void* p) { fn_801EF610(lbl_801EF5C8, p); }
};
struct OwnerList {
    OwnerHandle head, tail;
    void append(const OwnerHandle& h) {
        h.get()->prev = tail;
        if (!fn_801F7EB8(&tail))
            head = h;
        else
            tail.get()->next = h;
        tail = h;
    }
};
typedef char CheckOwnerSize[sizeof(Activable_Z) == 0x1C ? 1 : -1];

#endif
