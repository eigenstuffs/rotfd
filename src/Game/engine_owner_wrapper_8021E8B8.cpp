#include "Game/engine_owner_wrappers.h"

extern "C" signed char fn_8021E8B8(EngineOwnerWrapperVirtual* self,
    const EngineOwnerWrapperRecord* record, int unused, int arg)
{
    self->slot64(record->link, record, record->flags, arg);
    return 1;
}
