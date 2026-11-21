#include "Game/resource_flag_update_views.h"

extern "C" void fn_80069464(ResourceUpdateQuery* self, signed char state)
{
    *(signed char*)(resolveResourceUpdate(*self->getHandle()) + 0x3D2) = state;
}
