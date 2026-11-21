#include "Game/engine_array_growth.h"

static inline void allocate(EngineGrowthArray140 *self, int capacity)
{
    if (self->items)
        self->items = fn_8028FAF4(lbl_8028F698, self->items, self->capacity * sizeof(EngineGrowthItem140), capacity * sizeof(EngineGrowthItem140));
    else
        self->items = fn_8028FF24(lbl_8028F698, capacity * sizeof(EngineGrowthItem140));
}
static inline void resize(EngineGrowthArray140 *self, int count)
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
EngineGrowthOwner *fn_8020C744(EngineGrowthOwner *self, int argument)
{
    EngineGrowthRange range;
    self->table = &lbl_802EAFF0;
    self->first.count = 0;
    self->first.capacity = 0;
    self->first.items = 0;
    self->second.count = 0;
    self->second.capacity = 0;
    self->second.items = 0;
    self->argument = argument;
    self->value10 = lbl_8037AA40;
    self->value14 = lbl_8037AA80;
    resize(&self->second, 2);
    range = fn_8020C8CC(self, 0, 2);
    self->range.first = range.first;
    self->range.last = range.last;
    self->range.count = range.count;
    self->active = 1;
    self->value18 = 0;
    return self;
}
