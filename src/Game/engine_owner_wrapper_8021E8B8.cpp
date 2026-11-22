#include "Game/engine_owner_wrappers.h"

extern "C" signed char slot60__12ObjectMove_ZFv(EngineOwnerWrapperVirtual* self,
    const EngineOwnerWrapperRecord* record, int unused, int arg)
{
    self->slot64(record->link, record, record->flags, arg);
    return 1;
}
