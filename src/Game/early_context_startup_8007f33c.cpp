#include "Game/early_context_startup_views.h"

extern "C" void fn_8007F33C() {
    fn_801FA014(lbl_801E9D24.logger, lbl_8029D524);
    delete lbl_801E9D24.scene;
    lbl_801E9D24.scene = 0;
    delete lbl_801E9D24.input;
    lbl_801E9D24.input = 0;
}
