#define RETAINED_CONTROL_ZERO RecordZero_800B4D1C
#include "Game/early_actor_retained_control_views.h"

inline RetainedControlItem* findItem(RetainedControlRecord* self,
                                   RetainedControlName name) {
    for (int i = self->start; i < self->start + self->count; ++i) {
        RetainedControlItem* item = &self->items[i];
        if (item->name.word == name.word)
            return item;
    }
    return 0;
}

extern "C" void fn_800B4D1C(RetainedControlRecord* self,
                           unsigned char selection) {
    RetainedControlItem* item = findItem(self, RetainedControlName(lbl_802A04EC));
    if (item) {
        item->flags &= ~4;
        item->flags |= 1;
    }
    self->selection = selection;
    fn_80213A18(self);
    fn_800B3344(self);
    const Handle_801F7F10& original = self->handle;
    fn_801E2074(lbl_801E9D24.lists + self->selection * 0x4C,
                Handle_8002F6B0(original), 0);
}
