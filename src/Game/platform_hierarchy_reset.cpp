#include "Game/platform_followup_controls.h"

struct PlatformHierarchyReset {
    char unknown00[0xD9F8];
    int a, b;
};
struct PlatformHierarchyGlobals {
    char unknown00[0x120];
    void* child;
};
extern "C" {
void fn_8026863C(PlatformHierarchyReset*);
void fn_80267FCC(PlatformHierarchyReset*);
void fn_8023A9FC(void*);
extern PlatformHierarchyGlobals lbl_801E9D24;
}

extern "C" void fn_8026A63C(PlatformHierarchyReset* self) {
    fn_8026863C(self);
    fn_80267FCC(self);
    fn_8023A9FC(lbl_801E9D24.child);
    self->a = 0;
    self->b = 0;
}
