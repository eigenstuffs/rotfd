#include "Game/early_action_control_views.h"

extern "C" void fn_80094E40(ActionOwner* self){ActionVector value;value.x=self->actor->vector.x;value.y=self->actor->vector.y;value.z=self->actor->vector.z;self->actor->slot102(&value);}
