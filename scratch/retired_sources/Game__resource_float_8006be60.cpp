#include "Game/resource_float_update_views.h"

extern "C" signed char fn_8006BE60(ResourceFloatQuery* self, float value)
{
    ResourceFloatOwner* owner = (ResourceFloatOwner*)resolveResourceFloat(*self->getHandle());
    owner->field36C = value;
    return 1;
}
