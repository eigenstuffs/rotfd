#include "Game/engine_array_growth.h"

void fn_8023F668(EngineGrowthArray4 *self, int amount)
{
    if (amount) {
        if (self->items)
            self->items = fn_8028FAF4(lbl_8028F698, self->items, self->capacity * 4, amount * 4);
        else
            self->items = fn_8028FF24(lbl_8028F698, amount * 4);
    } else if (self->items) {
        fn_8028FD50(lbl_8028F698, self->items, self->capacity * 4);
        self->items = 0;
    }
}
