#include "Game/early_actor_event_control_views.h"

extern "C" void fn_800820E8(EventOwner* self) {
    self->actor->enabled40A = 0;
    EventComponent* component = resolveEvent(self->actor->handle)->second;
    if (component)
        component->value = resolveEventFirst(self->actor->handle)->first->value;
    if (lbl_803776B8 && lbl_803776B8->second)
        fn_80068158(lbl_803776B8, self->actor->record.key);
}
