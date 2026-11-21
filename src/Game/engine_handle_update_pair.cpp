#include "Game/engine_handle_updates_more.h"

extern "C" signed char fn_8020EC48(EngineHandleUpdatePair* self)
{
    if (!slot1C__12BaseObject_ZFv(self))
        return 0;
    if (fn_801F7EB8(&self->first))
        engineHandleUpdateResolve(self->first)->slot1C();
    if (fn_801F7EB8(&self->second))
        engineHandleUpdateResolve(self->second)->slot1C();
    return 1;
}
