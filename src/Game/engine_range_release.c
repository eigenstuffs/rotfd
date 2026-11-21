#include "Game/engine_range_operations.h"

static inline RangeOpsRange join(RangeOpsOwner *self, const RangeOpsRange *first,
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

static inline void assign(RangeOpsRange *to, RangeOpsRange value)
{
    to->first = value.first;
    to->last = value.last;
    to->count = value.count;
}

void fn_8020E938(RangeOpsOwner *self, RangeOpsRecord *record, int state)
{
    if (!record->state) {
        assign(&self->range, join(self, &self->range, &record->first));
        assign(&self->range, join(self, &self->range, &record->second));
    }
    record->state = state;
    record->value = 0;
}
