#ifndef ROTFD_MENU_BASE_NATIVE_INTERNAL_H
#define ROTFD_MENU_BASE_NATIVE_INTERNAL_H
#include "manipulator_callbacks_internal.h"
struct RenderSlot;
struct MenuGlobalsView {
    char unknown[0x114];
    RenderSlot* renderSlots;
};
extern "C" {
extern char lbl_8028F698[];
void fn_8028FD50(void*, void*, u32);
}
struct ManipulatorDraw_802BC9D0 : Manipulator_Z {
    virtual void slot40() = 0;
    virtual inline ~ManipulatorDraw_802BC9D0() {}
};
struct MenuHandle1 : Handle_801F7F10 {
    MenuHandle1() { value = 0; }
    ~MenuHandle1() {}
};
struct MenuHandle2 : MenuHandle1 {
    MenuHandle2() { value = 0; }
    ~MenuHandle2() {}
    MenuHandle2& operator=(const MenuHandle2& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
};
struct MenuWord {
    u32 value;
    ~MenuWord() {}
};
struct MenuWords {
    int count, capacity;
    MenuWord* data;
    MenuWords() : count(0), capacity(0), data(0) {}
    void releaseStorage() {
        if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(MenuWord));
            data = 0;
        }
    }
    ~MenuWords() {
        if (data) {
            for (int i = 0; i < count; i++) data[i].~MenuWord();
            releaseStorage();
            data = 0;
        }
    }
};
struct MenuBase_8021D7E4 : ManipulatorDraw_802BC9D0 {
    MenuHandle2 handle20, handle24;
    char unknown28[4];
    unsigned short field2C;
    char unknown2E[2];
    u32 field30;
    unsigned char selector;
    char pad35[3];
    MenuWords words;
    unsigned short field44;
    char unknown46[2];
    signed char field48;
    char pad49[3];
    MenuBase_8021D7E4(u32, unsigned char);
    virtual void slot18();
    virtual ~MenuBase_8021D7E4();
    virtual void slot38(float);
    virtual void slot40();
    virtual void slot44(unsigned char);
    virtual void slot48();
    // The external Menu table continues through slot54; those unused slots
    // are not declared by this constructor/destructor interface.
};
typedef char CheckMenuBase[sizeof(MenuBase_8021D7E4) == 0x4C ? 1 : -1];
#endif
