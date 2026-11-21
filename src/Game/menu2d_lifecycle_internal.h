#ifndef ROTFD_MENU2D_LIFECYCLE_INTERNAL_H
#define ROTFD_MENU2D_LIFECYCLE_INTERNAL_H

// Observed Menu2D layout; original C++ declarations and TU extent are unknown.
#include "menu_base_internal.h"
struct Manager;
struct RenderSlot { char unknown[0x4C]; };
struct Globals {
    char unknown[0x114];
    RenderSlot* renderSlots;
    Manager* manager;
};
extern "C" {
extern Globals lbl_801E9D24;
extern char lbl_801EF5C8[], lbl_8028F698[], __vt__15Menu2D_80216C9C[];
void fn_801EF610(void*, void*);
void fn_8028FD50(void*, void*, u32);
void fn_801F86C8(Manager*, const void*, short);
extern const float lbl_8037AD68, lbl_8037AD6C, lbl_8037AD70, lbl_8037AD74;
float fn_80284FA8(float);
}

struct HandleZero1 : Handle_801F7F10 {
    HandleZero1() { value = 0; }
    ~HandleZero1() {}
};
struct HandleZero2 : HandleZero1 {
    HandleZero2() { value = 0; }
    ~HandleZero2() {}
};
struct MenuHandle : HandleZero2 {
    MenuHandle(const Handle_801F7F10& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
    ~MenuHandle() {}
};

struct MenuElement {
    char unknown[0xBC];
    ~MenuElement() {}
};
struct MenuElements {
    int count, capacity;
    MenuElement* data;
    void releaseStorage() {
        if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(MenuElement));
            data = 0;
        }
    }
    ~MenuElements() {
        if (data) {
            for (int i = 0; i < count; i++)
                data[i].~MenuElement();
            releaseStorage();
            data = 0;
        }
    }
};
struct Menu2D_80216C9C : MenuBase_8021D7E4 {
    HandleZero2 handle4C;
    char unknown50[0x18];
    MenuElements elements;
    HandleZero2 handle74;
    float pulse;
    char unknown7C[0x50];
    ~Menu2D_80216C9C();
    static void operator delete(void* p) { fn_801EF610(lbl_801EF5C8, p); }
};
extern "C" {
void fn_80216228(Menu2D_80216C9C*);
}

typedef char CheckMenuBaseSize[sizeof(MenuBase_8021D7E4) == 0x4C ? 1 : -1];
typedef char CheckMenu2DSize[sizeof(Menu2D_80216C9C) == 0xCC ? 1 : -1];
typedef char CheckMenuElementSize[sizeof(MenuElement) == 0xBC ? 1 : -1];
#endif
