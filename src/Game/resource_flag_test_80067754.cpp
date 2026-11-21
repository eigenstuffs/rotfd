#include "Game/owner_flag_predicate_views.h"

extern "C" signed char fn_80067754(PredicateQuery* self, signed char state)
{
    if (!(*(unsigned long*)(resolvePredicate(self->getResource()->handle) + 0x120) & 0x10000))
        return state == 1;
    return state == 0;
}
