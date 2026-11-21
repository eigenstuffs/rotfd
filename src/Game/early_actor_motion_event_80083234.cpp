#include "Game/early_actor_motion_event_views.h"

extern "C" void fn_80083234(MotionOwner* self, double delta) {
    if (self->actor->enabled40D || (self->actor->flags & 0x8000000000ULL)) {
        fn_80285ED8(self->controller, 0x77, 0);
        fn_8007D6A0(&self->actor->record, fn_80092844(self->actor));
    }
    fn_80092BF4(self->actor, 0xA, delta);
    fn_80092DAC(self->actor, delta);
}
