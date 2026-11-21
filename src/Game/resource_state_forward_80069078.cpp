#include "Game/resource_state_forward_views.h"

extern "C" signed char fn_80069078(ForwardQuery* self, signed char value)
{
    return fn_8006B220(self, resolveForward(self->getResource()->handle), value);
}
