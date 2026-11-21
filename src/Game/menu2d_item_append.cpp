// Append an owned menu item and then its address to the inherited pointer array.
#include "menu2d_item_append_internal.h"

extern "C" int fn_80216A40(Menu2DAppendView* self, const MenuItem& item) {
    self->elements.append(item);
    return self->pointers.append(&self->elements.data[self->elements.count - 1]);
}
