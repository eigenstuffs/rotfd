#include "Game/early_camera_state_views.h"

extern "C" void fn_8007682C(CameraState* self) {
    if (self->state == 1) {
        if (self->timer <= 20)
            fn_8007626C(self, 2);
    } else if (self->state == 2) {
        CameraVector position;
        fn_80076D98(self, &position);
        self->desired = CameraVector(position, lbl_803789CC);
        self->current = self->desired;
    }
}
