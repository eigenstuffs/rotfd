#include "Game/resource_runtime_update_views.h"

extern "C" void fn_8006EC64(ResourceRuntimeQuery* self, unsigned char value)
{
    RuntimeOwner* owner = (RuntimeOwner*)resolveResourceRuntime(*self->getHandle());
    owner->byte = value;
}
