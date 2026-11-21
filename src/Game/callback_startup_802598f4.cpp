#include "Game/callback_startup_internal.h"

struct CallbackFlagTemporary : CallbackStartupPrefix {
    CallbackFlagTemporary() {
        __ct__24CallbackControl_802ECC00Fv(this);
        table = lbl_802EC8A8;
        flags &= ~4ULL;
        flags |= 8ULL;
    }

    ~CallbackFlagTemporary() {
        __dt__17LodAgent_802EC8A8Fv(this, -1);
    }
};

extern "C" void fn_802598F4() {
    lbl_80378040 = 0;
    fn_8025BCC4();
    CallbackFlagTemporary object;
}
