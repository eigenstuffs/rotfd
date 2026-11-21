#include "Game/early_actor_phase_control_views.h"

extern "C" void fn_80081B04(PhaseOwner* self) {
    fn_8025795C(self->controller, 16, 0);
    self->actor->enabled405 = 1;
    self->actor->enabled406 = 1;
    if (lbl_803776B8 && lbl_803776B8->first)
        fn_8006803C(lbl_803776B8, self->actor->record.key);
}
