#include "Game/resource_state_forward_views.h"

extern "C" signed char fn_80068FE4(ForwardQuery* self, signed char value)
{
    return fn_80069CA8(self, resolveForward(self->getResource()->handle), value);
}
