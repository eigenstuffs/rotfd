#include "Game/engine_record_dispatch.h"

extern "C" signed char fn_80235C28(EngineDispatchSmallOwner* self)
{
    if (!slot1C__12BaseObject_ZFv(self))
        return 0;
    if (fn_801F7EB8(&self->target0))
        engineDispatchResolve(self->target0)->slot1C();
    if (fn_801F7EB8(&self->target1))
        engineDispatchResolve(self->target1)->slot1C();
    return 1;
}
