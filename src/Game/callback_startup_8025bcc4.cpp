#include "Game/callback_startup_internal.h"

inline void constructCallbackStartup(CallbackStartupPrefix* self) {
    __ct__23CallbackSingle_802ECA18Fv(self);
    self->table = lbl_802ECC00;
    self->flags &= ~1ULL;
    self->flags |= 4ULL;
}

extern "C" void fn_8025BCC4() {
    lbl_80378060 = 0;
    fn_8025A930();
    CallbackStartupPrefix object;
    constructCallbackStartup(&object);
    CallbackStartupWords callback = lbl_802ECBB8;
    fn_8025E714(&object, &callback);
    fn_80020FE8(&object, -1);
}
