#include "Game/owner_cleanup_virtual_view_8009A8AC.h"
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
struct Handle_801F7F10 {
    u32 word;
    ~Handle_801F7F10();
};
struct H1:Handle_801F7F10 {
};
struct H2:H1 {
};
struct H3:H2 {
};
struct H4:H3 {
};
extern "C" {
    extern char lbl_802BAB50[];
    void fn_8009009C(void*,int);

}
struct Object_80098A70 {
    u32 unknown00[2];
    void*vtable;
    char unknown0C[0x318-0xC];
    void*secondaryVtable;
    ~Object_80098A70();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_80098A70::~Object_80098A70() {
    vtable=lbl_802BAB50;
    secondaryVtable=lbl_802BAB50+0x170;
    reinterpret_cast<OwnerCleanupVirtualView_8009A8AC*>(this)->OwnerCleanupVirtualView_8009A8AC::cleanup(0);
}
