#include "Game/engine_range_allocate.h"

static inline void allocate(RangeAllocateArray140 *self, int count)
{
    if (count) {
        if (self->items)
            self->items = fn_8028FAF4(lbl_8028F698, self->items,
                self->capacity * sizeof(RangeAllocateItem140), count * sizeof(RangeAllocateItem140));
        else
            self->items = fn_8028FF24(lbl_8028F698, count * sizeof(RangeAllocateItem140));
    } else if (self->items) {
        fn_8028FD50(lbl_8028F698, self->items, self->capacity * sizeof(RangeAllocateItem140));
        self->items = 0;
    }
}

static inline void resize(RangeAllocateArray140 *self, int count)
{
    int i;
    if (count > self->count) {
        allocate(self, count);
        self->capacity = count;
        for (i = self->count; i < count; i++) {}
        self->count = count;
    } else if (count < self->count) {
        for (i = self->count - 1; i >= count; i--) {}
        allocate(self, count);
        self->capacity = count;
        self->count = count;
    }
}

signed char fn_8020E558(RangeAllocateOwner *self, RangeAllocateRecord *record, short count)
{
    if (!record)
        return 0;
    if (record->state != 2)
        return 0;
    if (!count)
        return 0;
    if (self->range.count < count)
        fn_8020E8B0(self, count);
    if (self->range.count < count) {
        int old;
        int growth;
        RangeAllocateRange created;
        RangeAllocateRange joined;
        old = self->entries.count;
        growth = count + 16;
        if (old + growth > 32000)
            return 0;
        resize(&self->entries, old + growth);
        created = fn_8020C8CC(self, (short)old, (short)growth);
        joined = fn_8020E814(self, &self->range, &created);
        self->range.first = joined.first;
        self->range.last = joined.last;
        self->range.count = joined.count;
    }
    record->state = 0;
    record->first.count = 0;
    record->first.first = -1;
    record->first.last = -1;
    record->second.count = count;
    record->second.first = self->range.first;
    self->range.count -= count;
    while (count--) {
        record->second.last = self->range.first;
        self->range.first = *(short *)((char *)self->entries.items + self->range.first * 140 + 138);
    }
    *(short *)((char *)self->entries.items + record->second.last * 140 + 138) = -1;
    if (!self->range.count) {
        self->range.last = -1;
        self->range.first = -1;
    }
    return 1;
}
