#include "Game/native_cleanup_table.h"
#include "Runtime.PPCEABI.H/NMWException.h"

typedef struct PlatformStartupState {
    const void *cleanup;
    unsigned char active04;
    unsigned char unknown05[0x84 - 5];
    unsigned char active84;
    unsigned char unknown85[0x175 - 0x85];
    unsigned char active175;
} PlatformStartupState;

extern PlatformStartupState lbl_801E9D24;
extern const char lbl_802EA894[];
extern DestructorChain lbl_8033E748;
extern void *fn_801ECBE0(void *, short);

void fn_801ECB84(void) {
    lbl_801E9D24.cleanup = &lbl_802EA8A0;
    lbl_801E9D24.active04 = 0;
    lbl_801E9D24.active84 = 0;
    lbl_801E9D24.active175 = 0;
    lbl_801E9D24.cleanup = lbl_802EA894;
    __register_global_object(&lbl_801E9D24, fn_801ECBE0, &lbl_8033E748);
}

__declspec(section ".ctors")
static void (*const platform_startup_reference)(void) = fn_801ECB84;
