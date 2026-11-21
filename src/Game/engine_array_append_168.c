#include "Game/engine_array_growth.h"

static inline void resize(EngineGrowthArray168 *self, int amount)
{
    if (amount) {
        if (self->items)
            self->items = fn_8028FAF4(lbl_8028F698, self->items, self->capacity * sizeof(EngineGrowthItem168), amount * sizeof(EngineGrowthItem168));
        else
            self->items = fn_8028FF24(lbl_8028F698, amount * sizeof(EngineGrowthItem168));
    } else if (self->items) {
        fn_8028FD50(lbl_8028F698, self->items, self->capacity * sizeof(EngineGrowthItem168));
        self->items = 0;
    }
}
int fn_80225C58(EngineGrowthArray168 *self, const EngineGrowthItem168 *source)
{
    EngineGrowthItem168 *output;
    if (self->count + 1 > self->capacity) {
        resize(self, self->capacity + 1);
        self->capacity += 1;
    }
    output = &self->items[self->count++];
    if (output)
        __ct__19BitNativeCopyRecordFRC19BitNativeCopyRecord(output, source);
    return self->count - 1;
}
