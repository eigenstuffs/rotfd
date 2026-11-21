#include "Game/early_camera_target_views.h"

extern "C" signed char fn_8007A980(TargetCamera* self, float delta) {
    if (self->state == 0 && self->enabled &&
        (self->current.x != self->target.x || self->current.y != self->target.y ||
         self->current.z != self->target.z)) {
        if (fn_8007ACAC(self) == 1) {
            if (self->state == 0) {
                self->up = TargetVector(lbl_8037899C, lbl_803789A4, lbl_8037899C);
                fn_8007D4B4(&self->direction, &self->up, &self->direction, lbl_80378A28, delta);
            }
            self->desired = self->target;
            self->current = self->target;
            return 1;
        }
        return fn_8007AA9C(self, delta);
    }
    return 0;
}
