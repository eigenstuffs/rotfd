#include "Game/platform_small_controls.h"

typedef unsigned int u32;
extern "C" {
int PADReset(u32);
extern u32 lbl_802ED6E8[4];
}

extern "C" void fn_8027639C(void*, short port) {
    PADReset(lbl_802ED6E8[port]);
}
