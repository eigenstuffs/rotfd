#include "Game/early_transform_phase_views.h"

extern "C" void fn_80074560(PhaseUpdater* self, void*, const PhaseVector* input, float delta) {
    float half = self->value * lbl_8037895C;
    float c = fn_8028506C(half);
    float s = fn_80284FA8(half);
    PhaseQuaternion q(c, lbl_80378958 * s, lbl_80378960 * s, lbl_80378958 * s);
    self->value -= delta * (lbl_80378964 * self->phase);
    self->node->slot46(input, &q, 0);
}
