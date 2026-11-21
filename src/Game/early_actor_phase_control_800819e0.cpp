#include "Game/early_actor_phase_control_views.h"

extern "C" void fn_800819E0(PhaseOwner* self, double delta) {
    fn_80092BF4(self->actor, 2, delta);
    int value = fn_80092844(self->actor);
    if (value != 2)
        fn_8007D6A0(&self->actor->record, value);
    fn_80092DAC(self->actor, delta);
}
