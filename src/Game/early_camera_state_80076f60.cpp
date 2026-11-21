#include "Game/early_camera_state_views.h"

extern "C" void fn_80076F60(CameraState* self) {
    if (self->state == 2) {
        CameraVector direction;
        fn_80077D28(self, &direction);
        direction *= lbl_803789D0;
        direction.y += lbl_803789CC;
        self->direction = direction;
    } else {
        self->direction.x = fn_8028506C(lbl_803789E8 * self->azimuth1C8);
        self->direction.y = fn_80284FA8(lbl_803789E8 * self->elevation1C0);
        self->direction.z = fn_80284FA8(lbl_803789E8 * self->azimuth1C8);
        self->direction *= lbl_803789D0;
        self->direction.y += lbl_803789CC;
    }
}
