#include "Game/engine_vector_owner.h"

static inline void freeItems(void* items)
{
    if (items)
        fn_801EF610(lbl_801EF5C8, (char*)items - 16);
}

void fn_8020C018(EngineVectorStorage* self, int rows, int width)
{
    self->width = width;
    fn_801EAC8C(self, rows, width);
    if (self->items)
        freeItems(self->items);

    rows *= self->width;
    self->items = __construct_new_array(
        fn_801EFA1C(lbl_801EF5C8, rows * 16 + 16, lbl_802AE024,
                   lbl_802AE3C8, 32, 4),
        fn_8020C0C4, 0, 16, rows);
}
