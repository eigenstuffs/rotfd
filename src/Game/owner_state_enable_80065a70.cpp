#include "Game/owner_state_query_views.h"

extern "C" void fn_80065A70(StateOwner* self, int argument)
{
    ((StateFlags*)resolveState(self->handle))->flags |= 0x400ULL;
    ((StateFlags*)resolveState(self->handle))->flags |= 0x1000000000ULL;
    fn_80063290(self, argument);
}
