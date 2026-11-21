#include "Game/platform_followup_controls.h"

struct PlatformControlPrefix { char unknown00[0x1C]; };
struct PlatformControlTarget : PlatformControlPrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
};
struct PlatformControlGlobals { char unknown00[0x154]; PlatformControlTarget* target; };
extern "C" PlatformControlGlobals lbl_801E9D24;

extern "C" int fn_80276A08(void*) {
    lbl_801E9D24.target->slot2();
    return 1;
}
