#include "Game/early_record_completion_views.h"

extern "C" signed char fn_80073B38(CompletionAgent* self) {
    if (!fn_80259F0C(self))
        return 0;
    if (fn_801F7EB8(&self->controller))
        resolveCompletion(self->controller)->slot5();
    return 1;
}
