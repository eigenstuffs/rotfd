#include "Game/owner_state_query_views.h"

extern "C" int fn_80066AB0(StateQuery* self, unsigned long value)
{
    unsigned long actual = fn_8009F170(resolveState(*self->getHandle()));
    if (actual == value)
        return 1;
    return 0;
}
