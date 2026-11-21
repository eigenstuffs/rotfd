#include "Game/resource_float_update_views.h"

extern "C" signed char fn_8006BEE8(ResourceFloatQuery* self, float value)
{
    ResourceFloatOwner* owner = (ResourceFloatOwner*)resolveResourceFloat(*self->getHandle());
    owner->field3B0 = value;
    return 1;
}
