#include "Game/early_transform_phase_views.h"

extern "C" void fn_80074708(PhaseUpdater* self, void*, const PhaseVector* input, float delta) {
    self->value = self->amplitude * fn_80284FA8(self->phase);
    float offset = self->value;
    PhaseVector position;
    position.x = input->x;
    position.y = offset + self->node->height;
    position.z = input->z;
    self->node->slot45(&position, 0);
    float rate = lbl_80378964;
    rate *= self->speed;
    self->phase += delta * rate;
    while (self->phase > lbl_8037896C)
        self->phase -= lbl_8037896C;
}
