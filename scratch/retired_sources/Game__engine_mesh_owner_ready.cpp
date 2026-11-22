#include "Game/engine_mesh_owner_controls.h"

extern "C" signed char fn_802460F8(EngineHandleApplyPrimary*);

extern "C" signed char fn_8026D150(EngineHandleApplyPrimary* self)
{
    return (signed char)(fn_802460F8(self) ? 1 : 0);
}
