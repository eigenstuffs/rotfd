#include "Game/engine_handle_apply.h"

extern "C" signed char fn_8024877C(EngineHandleApplySecondary* self)
{
    if (!slot1C__12BaseObject_ZFv(self))
        return 0;
    for (int i = 0; i < self->count; i++) {
        if (fn_801F7EB8(&self->items[i]))
            engineHandleApplyResolve(self->items[i])->slot1C();
    }
    return 1;
}
