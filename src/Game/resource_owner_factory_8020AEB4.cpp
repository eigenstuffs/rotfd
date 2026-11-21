// Resource-owner factory (allocation 0xDA10, header string lbl_802AE328,
// line 247) with the owner constructor inlined. The matching destructor is
// fn_8026A710 (src/Game/engine_resource_owner_teardown.cpp); the layout follows
// include/Game/engine_resource_owner_teardown.h.
//
// The original class was polymorphic with an unnamed vtable (lbl_802ED148).
// That vtable store is emulated: OwnerTable receives the derived `this` as a
// separate argument so the store is made through the derived constructor's
// pointer copy (r30) as in the original, while the Resource table store goes
// through the factory result (r31). The inline destructors (unused with
// exceptions off) are required for the original register assignment of the
// member-constructor pointers; they are emitted only as weak copies.
extern "C" {
extern char lbl_801EF5C8[];
void* fn_801EFA1C(void*, unsigned long, const char*, const char*, int, int);
extern const char lbl_802AE024[], lbl_802AE328[];
extern char lbl_802ED148[];
extern char __vt__17Resource_802E9E20[];
void fn_802676F4(void*);
void __ct__15BitSet_80207EE8Fv(void*);
void fn_8020B074(void*);
void fn_800927A0(void*);
void __construct_array(void*, void (*)(void*), void*, unsigned long, unsigned long);
}
inline void* operator new(unsigned long, void* address) { return address; }

typedef unsigned long Word;

struct BaseObject_Z {
    Word unknown00, identity;
    void* table;
    BaseObject_Z();
    ~BaseObject_Z();
};
struct Resource_802E9E20 : BaseObject_Z {
    Resource_802E9E20() { table = __vt__17Resource_802E9E20; }
    ~Resource_802E9E20() {}
};
struct OwnerTable : Resource_802E9E20 {
    // Stands in for the compiler's derived-vtable store.
    OwnerTable(OwnerTable* self) { self->table = lbl_802ED148; }
    ~OwnerTable() {}
};

struct Handle_801F7F10 {
    Word word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Handle1 : Handle_801F7F10 {
    Handle1() { word = 0; }
    ~Handle1() {}
};
struct Handle2 : Handle1 {
    Handle2() { word = 0; }
    ~Handle2() {}
};

struct Array {
    int count, capacity;
    void* data;
    Array() { count = 0; capacity = 0; data = 0; }
    ~Array() {}
};

struct Group {
    char raw[0x4044];
    Group() { fn_802676F4(this); }
};

struct Fixed {
    char raw[32];
    int count;
    Fixed() { count = 0; }
};

struct BitSet_80207EE8 {
    int count, capacity;
    Word* data;
    int bits;
    BitSet_80207EE8() { __ct__15BitSet_80207EE8Fv(this); }
    ~BitSet_80207EE8();
};

struct Sparse : Array {
    BitSet_80207EE8 occupied;
    int limit, used;
    Sparse() { limit = 0; used = 0; }
    ~Sparse() {}
};

struct Element20 { char raw[0x20]; };
struct Element48 { char raw[0x48]; };
struct Records20 {
    Element20 records[0x3C];
    Records20() { __construct_array(records, fn_8020B074, 0, sizeof(Element20), 0x3C); }
};
struct Records48 {
    Element48 records[0x3C];
    Records48() { __construct_array(records, fn_800927A0, 0, sizeof(Element48), 0x3C); }
};

struct ResourceOwner : OwnerTable {
    Array array0C, array18, array24;
    Handle2 handle30;
    Group group34, group4078, group80BC;
    Array arrayC100;
    Word unknownC10C;
    Fixed fixedC110;
    Array arrayC134;
    Fixed fixedC140;
    Handle2 handleC164, handleC168;
    Word unknownC16C;
    Sparse sparseC170;
    Records20 recordsC194;
    Word unknownC914;
    Records48 recordsC918;
    Word unknownD9F8[2];
    Array arrayDA00;
    Word unknownDA0C;
    ResourceOwner() : OwnerTable(this) {}
    ~ResourceOwner();
};
typedef char ResourceOwnerSize[sizeof(ResourceOwner) == 0xDA10 ? 1 : -1];

extern "C" ResourceOwner* fn_8020AEB4() {
    return new (fn_801EFA1C(lbl_801EF5C8, sizeof(ResourceOwner),
                            lbl_802AE024, lbl_802AE328, 247, 4)) ResourceOwner;
}
