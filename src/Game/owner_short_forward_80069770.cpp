#include "Game/resource_flag_update_views.h"

extern "C" signed char fn_80069770(ResourceUpdateQuery* self, short value)
{
    return fn_8009FABC(resolveResourceUpdate(*self->getHandle()), (short)value);
}
