#include "Game/resource_runtime_update_views.h"

extern "C" void fn_8006EDCC(RuntimeQuery* self, signed char value)
{
    self->state = value;
    if (value == 0)
        ((RuntimeOwner*)resolveResourceRuntime(*self->getHandle()))->sentinel = 0;
    else
        ((RuntimeOwner*)resolveResourceRuntime(*self->getHandle()))->sentinel = -1;
}
