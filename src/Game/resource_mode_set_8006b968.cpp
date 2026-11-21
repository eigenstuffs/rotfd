#include "Game/resource_mode_update_views.h"

extern "C" void fn_8006B968(ResourceModeQuery* self, unsigned char mode)
{
    if (mode == 0)
        self->getResource()->flags |= 0x100000000000ULL;
    else if (mode == 1)
        self->getResource()->flags |= 0x1000000ULL;
}
