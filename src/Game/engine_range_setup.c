#include "Game/engine_range_allocate.h"

RangeAllocateSetup *fn_8020BFA8(RangeAllocateSetup *self)
{
    RangeAllocateArray *array = &self->array;
    array->count = 0;
    array->capacity = 0;
    array->items = 0;
    self->value14 = 0;
    self->size = 3;
    fn_8020C018(array, 50,
        2 * ((self->size + 1) * (self->size + 1)) + ((self->size + 2) * (self->size + 2)));
    return self;
}
