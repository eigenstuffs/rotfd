#include "Game/early_actor_event_control_views.h"

extern "C" void fn_80080BC0(EventOwner* self) {
    resolveEvent(*self->actor->slot37(0))->flags |= 0x40000UL;
    EventActor* actor = self->actor;
    if (lbl_80378AA8 != actor->value && fn_801F7EB8(&actor->handle)) {
        EventComponent* component = resolveEvent(actor->handle)->second;
        if (component)
            component->value = actor->value;
    }
}
