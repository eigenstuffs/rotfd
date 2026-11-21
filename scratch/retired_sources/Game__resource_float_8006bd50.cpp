#include "Game/resource_float_update_views.h"

extern "C" signed char fn_8006BD50(ResourceFloatQuery* self, float value)
{
    ResourceFloatOwner* owner = (ResourceFloatOwner*)resolveResourceFloat(*self->getHandle());
    owner->field3BC = value;
    return 1;
}
