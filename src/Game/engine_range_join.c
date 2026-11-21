#include "Game/engine_range_operations.h"

RangeOpsRange fn_8020E814(RangeOpsOwner *self, const RangeOpsRange *first,
    const RangeOpsRange *second)
{
    RangeOpsRange result;
    if (!first->count)
        return *second;
    if (!second->count)
        return *first;
    *(short *)(self->items + first->last * 140 + 138) = second->first;
    *(short *)(self->items + second->first * 140 + 136) = first->last;
    result.first = first->first;
    result.last = second->last;
    result.count = first->count + second->count;
    return result;
}
