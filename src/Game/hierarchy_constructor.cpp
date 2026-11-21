extern "C" {
extern const char lbl_802AD948[12] = "ObjectsGame";
}

// Reconstructed native hierarchy constructor; private names describe observed ABI roles.
typedef unsigned long u32;
struct Manager;
struct Globals { char unknown[0x118]; Manager* manager; };
extern "C" Globals lbl_801E9D24;
struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    u32 value;
};
extern "C" {
void fn_801F86C8(Manager*, const void*, short);
Handle_801F7F10 fn_801B52EC(Manager*, const char*);
extern const char lbl_802AD948[];
}
struct ConstructorHandle1 : Handle_801F7F10 { ConstructorHandle1() { value = 0; } };
struct ConstructorHandle2 : ConstructorHandle1 { ConstructorHandle2() { value = 0; } };
struct ConstructorHandle3 : ConstructorHandle2 {
    ConstructorHandle3() { value = 0; }
    ConstructorHandle3(const Handle_801F7F10& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
    ConstructorHandle3& operator=(const ConstructorHandle3& source) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
        return *this;
    }
};
struct ConstructorList {
    int count, capacity;
    void* data;
    ConstructorList() { count = 0; capacity = 0; data = 0; }
};
struct RootStorage_80207414 { u32 unknown0, identity; };
struct BaseObject_Z : RootStorage_80207414 {
    BaseObject_Z();
    virtual ~BaseObject_Z();
    virtual void slot0C(u32);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
};
struct Hierarchy_80200478 : BaseObject_Z {
    ConstructorHandle2 owner;
    char name[0x80];
    ConstructorList primary, second, secondary, assigned;
    ConstructorHandle3 related;
    ConstructorList fourth, third;
    int count, activeCount, offset;
    char active;
    Hierarchy_80200478();
    virtual ~Hierarchy_80200478();
    virtual signed char slot1C();
};
typedef char HierarchySizeCheck[sizeof(Hierarchy_80200478) == 0xEC ? 1 : -1];

Hierarchy_80200478::Hierarchy_80200478() {
    count = 0;
    activeCount = 0;
    active = 0;
    related = ConstructorHandle3(fn_801B52EC(lbl_801E9D24.manager, lbl_802AD948));
    offset = -1;
}
