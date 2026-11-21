// Update the observed word at +0x14 and notify the engine object list.
typedef unsigned long u32;
struct Manager;
struct OwnerList;
struct Globals {
    char unknown0[0x118];
    Manager* manager;
    char unknown11C[0x1C];
    OwnerList* list;
};
extern "C" {
extern Globals lbl_801E9D24;
void fn_801F86C8(Manager*, const void*, short);
}
struct Handle_801F7F10 {
    u32 value;
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
    OwnerHandle(const IdentityHandle& h) {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
};
struct Object {
    u32 unknown0;
    Handle_801F7F10 identity;
    void* vtable;
    u32 prev, next;
    int field14;
    const Handle_801F7F10& getIdentity() const { return identity; }
};
extern "C" void fn_80212FC4(OwnerList*, const OwnerHandle&);

extern "C" void fn_80213920(Object* self, int mode) {
    if (mode != self->field14) {
        self->field14 = mode;
        OwnerHandle h = IdentityHandle(self->getIdentity());
        fn_80212FC4(lbl_801E9D24.list, h);
    }
}
