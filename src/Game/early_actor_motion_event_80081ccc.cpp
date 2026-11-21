#include "Game/early_actor_motion_event_views.h"

extern "C" void fn_80081CCC(MotionOwner* self) {
    MotionComponent* component = resolveMotion(self->actor->handle)->second;
    if (component)
        component->value = lbl_80378AD0;
    fn_8025795C(self->controller, 0x70, 0);
    if (lbl_803776B8 && lbl_803776B8->first)
        fn_8006803C(lbl_803776B8, self->actor->record.key);
}
