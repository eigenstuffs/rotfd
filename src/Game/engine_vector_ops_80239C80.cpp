#include "Game/engine_vector_ops.h"

extern "C" signed char fn_80239C80(EngineVectorCurveOwner* self)
{
    if (!slot1C__12BaseObject_ZFv(self))
        return 0;
    fn_801B0E28((char*)self + 0x10);
    if (fn_801F7EB8(&self->handle))
        engineVectorResolve(self->handle)->slot1C();
    return 1;
}
