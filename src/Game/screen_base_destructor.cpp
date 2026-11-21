#include "Game/late_screen_virtual_table.h"
// Reconstructed from GSQE78 code and exception records. Class suffixes identify
// observed native constructors, destructors, or vtables; original names are unknown.
typedef unsigned long u32;

extern "C" {
extern char lbl_801EF5C8[];
extern int lbl_80377824;
extern int lbl_80377820;
extern const char __vt__22LoadingScreen_800B9214[];
void fn_801EF610(void*, void*);
void fn_802548B8(void*);
}

struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
    static void operator delete(void* p) throw() {
        fn_801EF610(lbl_801EF5C8, p);
    }
};
struct Handle_80020478 : Handle_801F7F10 {
    Handle_80020478() { value = 0; }
    ~Handle_80020478() {}
};
struct Handle_80021BCC : Handle_80020478 {
    Handle_80021BCC() { value = 0; }
    ~Handle_80021BCC() {}
};
struct Handle_800B92F0 : Handle_80021BCC {
    Handle_800B92F0() { value = 0; }
    ~Handle_800B92F0() {}
};

struct ObjectPrefix {
    u32 unknown[2];
};
struct Object_8025F0D8 : ObjectPrefix {
    Object_8025F0D8();
    ~Object_8025F0D8();
    const void* vtable;
    char unknown0C[0x3C];
    static void operator delete(void* p) throw() {
        fn_801EF610(lbl_801EF5C8, p);
    }
};
struct ScreenBase_800B9368 : Object_8025F0D8 {
    Handle_800B92F0 member48;
    u32 unknown4C;
    ScreenBase_800B9368() {}
    ~ScreenBase_800B9368();
};

ScreenBase_800B9368::~ScreenBase_800B9368() { vtable = &__vt__19ScreenBase_800B9368; }
