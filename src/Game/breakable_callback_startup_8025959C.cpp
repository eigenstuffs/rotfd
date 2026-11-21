#include "Game/engine_callback_breakable_ctor.h"

extern "C" {
extern unsigned long lbl_80378038;
void fn_8025BCC4();
}

inline Breakable_802EC810::Breakable_802EC810() : BreakableVtable(this) {
    flags |= 0x40ULL;
}

struct Object_80020F2C : Breakable_802EC810 {
    Object_80020F2C() {}
    ~Object_80020F2C();
};

extern "C" void fn_8025959C() {
    lbl_80378038 = 0;
    fn_8025BCC4();
    Object_80020F2C temporary;
}
