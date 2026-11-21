#include "Game/resource_float_update_views.h"

extern "C" void fn_8006C910(ResourceFloatQuery* self, float value)
{
    ResourceFloatOwner* owner = (ResourceFloatOwner*)resolveResourceFloat(*self->getHandle());
    owner->field3E4 = value;
}
