#include "Game/late_screen_virtual_table.h"
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
struct Handle_801F7F10 {
    unsigned int word;
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
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" char __vt__22LoadingScreen_800C0600[];
extern "C" {
    extern char __vt__22LoadingScreen_800B9214[];
}
struct Object_8025F0D8 {
    char unknown00[0x48];
    ~Object_8025F0D8();
};
struct ScreenBase:Object_8025F0D8 {
    H3 handle48;
    unsigned int unknown4C;
    ~ScreenBase() {
        *(void**)((char*)this+8)=&__vt__19ScreenBase_800B9368;
    }
};
struct LoadingBase:ScreenBase {
    H3 handle50;
    ~LoadingBase() {
        *(void**)((char*)this+8)=__vt__22LoadingScreen_800B9214;
    }
};
struct Object_800C0600:LoadingBase {
    ~Object_800C0600();
    static void operator delete(void*p)throw() {
        dispose(p);
    }
};
Object_800C0600::~Object_800C0600() {
    *(void**)((char*)this+8)=__vt__22LoadingScreen_800C0600;
}
