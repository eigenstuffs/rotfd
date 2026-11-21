#include "Game/early_actor_motion_event_views.h"

extern "C" void fn_800830D0(MotionOwner* self) {
    self->actor->acceleration = game_vec3_zero;
    self->actor->position = MotionVector(self->actor->position, lbl_80378AD0);
    self->actor->velocity = MotionVector(self->actor->velocity, lbl_80378AD0);
    MotionVector offset = self->actor->offset;
    self->actor->acceleration += offset;
    self->actor->clearFlags(0x1000000000ULL);
    self->actor->clearFlags(0x8000000000ULL);
    if (fn_801F7EB8(&self->actor->selected))
        fn_80257828(self->controller, 0x78, 0x77, 0);
    else
        fn_80257828(self->controller, 0x19, 0x77, 0);
    fn_80255D88(self->controller, 4, 0xF, 0, 0);
    if (lbl_803776B8 && lbl_803776B8->first)
        fn_8006803C(lbl_803776B8, self->actor->record.key);
}
