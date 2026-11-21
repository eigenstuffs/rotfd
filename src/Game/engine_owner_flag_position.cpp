#include "Game/engine_owner_flag_controls.h"

extern "C" void fn_8021F568(OwnerFlagControls* self, void*, const void* point)
{
    self->slotBC(point, 0);
}
