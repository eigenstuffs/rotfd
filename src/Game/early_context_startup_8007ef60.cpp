#include "Game/early_context_startup_views.h"

extern "C" int fn_8007EF60() {
    const char* pool = game_type_registry_SpongeBob___RegisterGameClasses;
    fn_8001F834();
    if (lbl_80377760) {
        fn_8001F518(lbl_80377760, 1);
        lbl_80377760 = 0;
    }
    if (!lbl_80377760) {
        void* storage = fn_801EFA1C(&lbl_801EF5C8, 1, pool + 0x2EC,
                                  pool + 0x550, 0xF1, 4);
        if (storage)
            storage = fn_8001F38C(storage);
        lbl_80377760 = (StartupSingleton*)storage;
    }
    if (lbl_801E9D24.logger->mode != 2) {
        fn_801FA014(lbl_801E9D24.logger, pool + 0x55C);
        return 0;
    }
    return fn_8001F754(lbl_80377760, lbl_801E9D24.logger->device);
}
