#include "Game/resource_flag_update_views.h"

extern "C" void fn_800692B4(ResourceUpdateQuery* self, unsigned char state)
{
    if (state == 0)
        self->getResource()->flags &= ~0x20000ULL;
    else
        self->getResource()->flags |= 0x20000ULL;
}
