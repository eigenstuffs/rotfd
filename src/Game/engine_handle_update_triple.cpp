#include "Game/engine_handle_updates_more.h"

extern "C" signed char fn_8022AE2C(EngineHandleUpdateTriple* self)
{
    int i;
    if (!slot1C__12BaseObject_ZFv(self))
        return 0;
    for (i = 0; i < self->firstCount; i++)
        engineHandleUpdateResolve(self->first[i])->slot1C();
    for (i = 0; i < self->secondCount; i++)
        engineHandleUpdateResolve(self->second[i])->slot1C();
    for (i = 0; i < self->thirdCount; i++)
        engineHandleUpdateResolve(self->third[i])->slot1C();
    return 1;
}
