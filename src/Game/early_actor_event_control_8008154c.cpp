#include "Game/early_actor_event_control_views.h"

extern "C" void fn_8008154C(EventOwner* self) {
    self->actor->flags |= 0x1000000000ULL;
    if (self->actor->hasFlags(0x8000000000000ULL) &&
        fn_8007D604(&self->actor->record, 0x21))
        fn_8025795C(self->controller, 0x1B, 0);
    else
        fn_8025795C(self->controller, 1, 0);
    self->actor->enabled405 = 1;
    self->actor->enabled406 = 1;
    if (lbl_803776B8 && lbl_803776B8->first)
        fn_8006803C(lbl_803776B8, self->actor->record.key);
}
