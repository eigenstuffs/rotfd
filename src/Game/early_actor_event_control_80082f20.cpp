#include "Game/early_actor_event_control_views.h"

extern "C" void fn_80082F20(EventOwner* self, float delta) {
    if (self->actor->hasFlags(0x8000000000ULL) ||
        (self->actor->enabled40D && self->actor->threshold < lbl_80378AF0)) {
        fn_80285ED8(self->controller, 0x77, 0);
        fn_8007D6A0(&self->actor->record, fn_80092844(self->actor));
    }
    fn_80092BF4(self->actor, 0xA, delta);
    fn_80092DAC(self->actor, delta);
}
