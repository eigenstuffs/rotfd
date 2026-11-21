#include "Game/event_state_notify_views.h"

extern "C" void fn_80096F3C(StateNotifyOwner* self, int,
                           const StateVector* position)
{
    if (self->previous == 8 && self->state == 5)
        self->notify(&self->position, 0);
    else
        self->notify(position, 0);
    if (self->previous != self->state)
        self->previous = self->state;
}
