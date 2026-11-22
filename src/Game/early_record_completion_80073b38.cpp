#include "Game/early_record_completion_views.h"

extern "C" signed char fn_80073B38(CompletionAgent* self) {
    if (!slot1C__13MovingAgent_ZFv(self))
        return 0;
    if (fn_801F7EB8(&self->controller))
        resolveCompletion(self->controller)->slot5();
    return 1;
}
