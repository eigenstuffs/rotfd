#include "Game/early_record_completion_views.h"

static inline const short& completionSlot(const CompletionAgent* node) {
    return node->slot;
}

// Complete the menu record once all eight node slots match their record IDs.
extern "C" signed char fn_8007256C(CompletionOwner* self) {
    if (lbl_801E9D24.scene->screen->getPending() > 0)
        return 0;
    if (self->count == 0)
        return 0;

    for (unsigned short i = 0; i < 8; ++i) {
        if (self->records[i].id != completionSlot(self->records[i].node))
            return 0;
    }

    fn_800732B8(self->object);
    lbl_801E9D24.input->enabled = 0;
    fn_802073E8(self, 0xAA, lbl_803776B8->getResource(), lbl_8037890C);
    self->state = 0;
    CompletionScreen* screen = lbl_801E9D24.scene->screen;
    screen->records[screen->current].completed = 1;
    return 1;
}
