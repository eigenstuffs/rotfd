#include "Game/early_actor_motion_event_views.h"

extern "C" void fn_80082A7C(MotionOwner* self, float delta) {
    if (self->actor->hasFlags(0x8000000000ULL) ||
        (self->actor->enabled40D && self->actor->position.y < lbl_80378AF0))
        fn_8007D6A0(&self->actor->record, fn_80092844(self->actor));
    fn_80092BF4(self->actor, 9, delta);
    fn_80092DAC(self->actor, delta);
}
