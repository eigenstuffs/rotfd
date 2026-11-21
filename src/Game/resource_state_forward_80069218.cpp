#include "Game/resource_state_forward_views.h"

extern "C" signed char fn_80069218(ForwardQuery* self, unsigned char value)
{
    return fn_8006B470(self, resolveForward(self->getResource()->handle), value);
}
