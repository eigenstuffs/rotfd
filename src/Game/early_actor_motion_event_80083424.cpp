#include "Game/early_actor_motion_event_views.h"

extern "C" void fn_80083424(MotionOwner* self, double delta) {
    if (self->actor->hasFlags(0x8000000000ULL))
        fn_8007D6A0(&self->actor->record, fn_80092844(self->actor));
    fn_80092BF4(self->actor, 0xC, delta);
    fn_80092DAC(self->actor, delta);
}
