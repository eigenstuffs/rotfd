#include "Game/early_camera_target_views.h"

extern "C" signed char fn_8007AA9C(TargetCamera* self, float delta) {
    if (fn_80079D3C(self) == 1 && fn_8007AB68(self, delta)) {
        self->desired = self->target;
        self->current = self->target;
        return 1;
    }
    self->target = self->current;
    self->desired = self->current;
    return 0;
}
