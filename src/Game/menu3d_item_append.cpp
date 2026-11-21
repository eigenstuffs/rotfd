// Append an owned menu item and then its address to the inherited pointer array.
#include "menu2d_item_append_internal.h"

// The observed item and both array layouts are shared with Menu2D.
typedef Menu2DAppendView Menu3DAppendView;

extern "C" int fn_80219164(Menu3DAppendView* self, const MenuItem& item) {
    self->elements.append(item);
    return self->pointers.append(&self->elements.data[self->elements.count - 1]);
}
