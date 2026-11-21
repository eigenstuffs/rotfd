#include "Game/resource_runtime_update_views.h"

extern "C" void fn_8006C808(ResourceRuntimeQuery* self, signed char value)
{
    RuntimeOwner* owner = (RuntimeOwner*)resolveResourceRuntime(*self->getHandle());
    owner->option = value;
}
