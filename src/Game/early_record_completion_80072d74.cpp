#include "Game/early_record_completion_views.h"

extern "C" void fn_80072D74(CompletionAgent* self) {
    fn_8025A3C8(self, fn_801B52EC(lbl_801E9D24.manager, lbl_8029C9B8));
    fn_8002B780(self);
    self->flags |= 1ULL << 17;
    self->flags &= ~(1ULL << 24);
}
