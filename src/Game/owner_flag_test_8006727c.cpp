#include "Game/owner_flag_predicate_views.h"

extern "C" signed char fn_8006727C(PredicateQuery* self, signed char state)
{
    if (!(((PredicateFlags*)resolvePredicate(*self->getHandle()))->flags & 0x8000000000ULL))
        return state == 1;
    return state == 0;
}
