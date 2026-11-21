#include "Game/resource_float_update_views.h"

extern "C" signed char fn_8006BCC8(ResourceFloatQuery* self, float value)
{
    ResourceFloatOwner* owner = (ResourceFloatOwner*)resolveResourceFloat(*self->getHandle());
    owner->field3B8 = value;
    return 1;
}
