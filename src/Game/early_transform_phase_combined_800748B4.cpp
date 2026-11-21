#include "Game/early_transform_phase_views.h"

/* Combined phase updater: writes the sinusoidal height offset, forms the
 * half-angle quaternion, dispatches the node transform virtual, then advances
 * the spin angle and phase and wraps the phase by the external period. */
extern "C" void fn_800748B4(PhaseUpdater* self, void*, const PhaseVector* input, float delta) {
    self->value = self->amplitude * fn_80284FA8(self->phase);
    float offset = self->value;
    PhaseVector position;
    position.x = input->x;
    position.y = offset + self->node->height;
    position.z = input->z;
    float half = self->speed * lbl_8037895C;
    float c = fn_8028506C(half);
    float s = fn_80284FA8(half);
    PhaseQuaternion q(c, lbl_80378958 * s, lbl_80378960 * s, lbl_80378958 * s);
    self->node->slot46(&position, &q, 0);
    self->speed -= delta * (lbl_80378964 * self->angleDecay);
    self->phase += delta * (lbl_80378964 * self->angleSpeed);
    while (self->phase > lbl_8037896C)
        self->phase -= lbl_8037896C;
}
