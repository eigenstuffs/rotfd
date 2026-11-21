#include "Game/early_actor_motion_event_views.h"

extern "C" void fn_800882A8(MotionOwner* self) {
    float height = self->actor->height;
    self->actor->position = MotionVector(self->actor->position, lbl_80378AD0);
    self->actor->velocity = MotionVector(self->actor->velocity, lbl_80378AD0);
    self->actor->acceleration = game_vec3_zero;
    self->actor->acceleration += MotionVector(lbl_80378AD0, height, lbl_80378AD0);
    self->actor->clearFlags(0x1000000000ULL);
    self->actor->clearFlags(0x8000000000ULL);
    fn_80257828(self->controller, 0x78, 0x77, 0);
    if (lbl_801E9D24.scene->mode->state == 6)
        fn_80255D88(self->controller, 0x9A, 0xF, 0, 0);
    else
        fn_80255D88(self->controller, 3, 0xF, 0, 0);
    if (lbl_803776B8 && lbl_803776B8->first)
        fn_8006803C(lbl_803776B8, self->actor->record.key);
}
