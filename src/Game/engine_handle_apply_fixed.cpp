#include "Game/engine_handle_apply.h"

extern "C" signed char fn_802433C4(EngineHandleApplyFixed* self)
{
    int i;
    if (!slot1C__12BaseObject_ZFv(self))
        return 0;
    for (i = 0; i < 10; i++) {
        if (fn_801F7EB8(&self->fixed[i]))
            engineHandleApplyResolve(self->fixed[i])->slot1C();
    }
    for (i = 0; i < self->firstCount; i++) {
        if (fn_801F7EB8(&self->first[i]))
            engineHandleApplyResolve(self->first[i])->slot1C();
    }
    for (i = 0; i < self->secondCount; i++) {
        if (fn_801F7EB8(&self->second[i]))
            engineHandleApplyResolve(self->second[i])->slot1C();
    }
    return 1;
}
