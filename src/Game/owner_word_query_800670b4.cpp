#include "Game/owner_flag_predicate_views.h"

extern "C" unsigned short fn_800670B4(PredicateQuery* self)
{
    return *(unsigned long*)(resolvePredicate(*self->getHandle()) + 0x3D8);
}
