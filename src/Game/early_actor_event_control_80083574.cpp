#include "Game/early_actor_event_control_views.h"

extern "C" void fn_80083574(EventOwner* self) {
    fn_80257828(self->controller, 0x3E, 0x79, 0);
    EventComponent* component = resolveEvent(self->actor->handle)->second;
    if (component)
        component->value = lbl_80378AD8;
    if (lbl_803776B8 && lbl_803776B8->first)
        fn_8006803C(lbl_803776B8, self->actor->record.key);
}
