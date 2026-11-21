#include "Game/early_record_completion_views.h"

extern "C" void fn_800738D0(CompletionAgent* self) {
    fn_8025BBA8(self);
    fn_8025A3C8(self, fn_801B52EC(lbl_801E9D24.manager, lbl_8029CA48));
    self->slot35(0, 0);
    resolveCompletion(self->controller)->field228 = lbl_80378938;
    resolveCompletion(self->controller)->setPair(lbl_8037893C);
    resolveCompletion(self->controller)->field2BC = lbl_80378940;
    resolveCompletion(self->controller)->field2C0 = lbl_80378944;
    resolveCompletion(self->controller)->field2C4 = lbl_80378948;
    self->flags |= 1ULL << 17;
    self->slot21(0x87);
    self->slot22(0x87);
}
