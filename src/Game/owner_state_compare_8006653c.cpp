#include "Game/owner_state_query_views.h"

extern "C" int fn_8006653C(StateQuery* self, unsigned char state)
{
    if (state == *(int*)(resolveState(*self->getHandle()) + 0x320))
        return 1;
    return 0;
}
