#include "Game/resource_runtime_update_views.h"

extern "C" void fn_8006C78C(ResourceRuntimeQuery* self, signed char enabled)
{
    if (enabled)
        self->getResource()->flags &= ~0x1000000ULL;
    else
        self->getResource()->flags |= 0x1000000ULL;
}
