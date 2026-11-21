#include "Game/engine_handle_updates_more.h"

extern "C" signed char fn_80211300(EngineHandleUpdateFixed* self)
{
    if (!slot1C__12BaseObject_ZFv(self))
        return 0;
    if (fn_801F7EB8(&self->first))
        engineHandleUpdateResolve(self->first)->slot1C();
    if (fn_801F7EB8(&self->second))
        engineHandleUpdateResolve(self->second)->slot1C();
    for (int i = 0; i < 3; i++) {
        if (fn_801F7EB8(&self->fixed[i]))
            engineHandleUpdateResolve(self->fixed[i])->slot1C();
    }
    if (fn_801F7EB8(&self->last))
        engineHandleUpdateResolve(self->last)->slot1C();
    return 1;
}
