#include "Game/engine_owner_flag_controls.h"

extern "C" signed char fn_8021F2D0(const OwnerFlagControls* self)
{
    signed char result;
    if (self->flags & 2ULL)
        result = 1;
    else
        result = 0;
    return result;
}

extern "C" signed char fn_8021F308(const OwnerFlagControls* self)
{
    signed char result;
    if (self->flags & 1ULL)
        result = 1;
    else
        result = 0;
    return result;
}
