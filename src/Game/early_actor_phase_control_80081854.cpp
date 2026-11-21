#include "Game/early_actor_phase_control_views.h"

extern "C" void fn_80081854(PhaseOwner* self, double delta) {
    fn_80092BF4(self->actor, 1, delta);
    int value = fn_80092844(self->actor);
    if (value != 1)
        fn_8007D6A0(&self->actor->record, value);
    fn_80092DAC(self->actor, delta);
}
