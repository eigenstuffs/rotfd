#include "Game/early_controller_flag_query_views.h"

extern "C" signed char fn_800669D0(ControlFlagObject* self,
    ControlFlagObject* other, unsigned char operation) {
    if (flagSet(other->flags, 0x80000000000ULL)
        && (other->flags & 0x200000000000ULL)
        && fn_8007D604((char*)resolveControlFlag(other->controller) + 0x318, operation))
        return 1;
    return 0;
}
