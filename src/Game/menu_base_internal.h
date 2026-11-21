#ifndef ROTFD_MENU_BASE_INTERNAL_H
#define ROTFD_MENU_BASE_INTERNAL_H

// Shared observed Menu base storage; address-qualified names remain working names.
typedef unsigned long u32;
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct RenderSlot;
struct Activable_Z;
extern "C" {
void fn_802139D8(Activable_Z*);
void fn_80213A18(Activable_Z*);
void fn_801E1F3C(RenderSlot*, const Handle_801F7F10&);
void fn_801E2074(RenderSlot*, const Handle_801F7F10&, signed char);
}
struct MenuBase_8021D7E4 {
    u32 unknown0;
    Handle_801F7F10 identity;
    void* vtable;
    char unknownC[0x10];
    float accumulated;
    char unknown20[0x14];
    unsigned char selector;
    char unknown35[0x17];
    ~MenuBase_8021D7E4();
    const Handle_801F7F10& getIdentity() const { return identity; }
};
typedef char CheckSharedMenuBaseSize[sizeof(MenuBase_8021D7E4) == 0x4C ? 1 : -1];
#endif
