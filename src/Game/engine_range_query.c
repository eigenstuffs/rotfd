#include "Game/engine_range_dispatch.h"

RangeDispatchRecord *fn_8020E46C(RangeDispatchOwner *self, const int *index,
    signed char *changed)
{
    RangeDispatchRecord *record;
    if (*index == -1)
        return 0;
    if (*index >= self->records.count)
        return 0;
    record = &self->records.items[*index];
    if (changed)
        *changed = 0;
    if (record->state == 1)
        return 0;
    if (record->state == 2) {
        if (!fn_8020E558(self, record, record->first.count + record->second.count))
            return 0;
        if (changed)
            *changed = 1;
    }
    record->stamp = self->stamp;
    record->value = self->unknown30;
    return record;
}
