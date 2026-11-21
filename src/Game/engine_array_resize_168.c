#include "Game/engine_array_operations_more.h"

static inline void allocate(ArrayOpsArray168 *self, int count)
{
    if (count) {
        if (self->items)
            self->items = fn_8028FAF4(lbl_8028F698, self->items,
                self->capacity * sizeof(ArrayOpsItem168), count * sizeof(ArrayOpsItem168));
        else
            self->items = fn_8028FF24(lbl_8028F698, count * sizeof(ArrayOpsItem168));
    } else if (self->items) {
        fn_8028FD50(lbl_8028F698, self->items, self->capacity * sizeof(ArrayOpsItem168));
        self->items = 0;
    }
}

void fn_80227380(ArrayOpsArray168 *self, int count, signed char retain)
{
    int i;
    if (count > self->count) {
        if (count > self->capacity || !retain) {
            allocate(self, count);
            self->capacity = count;
        }
        for (i = self->count; i < count; i++) {
            ArrayOpsItem168 *p = &self->items[i];
            if (p)
                __ct__16BitDefaultRecordFv(p);
        }
        self->count = count;
    } else if (count < self->count) {
        if (retain) {
            self->count = count;
        } else {
            allocate(self, count);
            self->capacity = count;
            self->count = count;
        }
    }
}
