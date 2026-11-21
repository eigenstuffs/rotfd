#include "Game/engine_owner_flag_controls.h"

struct IndexedFlagControls {
    char unknown00[0x188];
    char* records;
};

extern "C" void fn_80224B7C(IndexedFlagControls* self, unsigned long long mask, int index)
{
    *(unsigned long long*)(self->records + index * 0xA8 + 0x38) &= ~mask;
}

extern "C" signed char fn_80224BB4(const IndexedFlagControls* self,
    unsigned long long mask, int index)
{
    signed char result;
    if (*(unsigned long long*)(self->records + index * 0xA8 + 0x38) & mask)
        result = 1;
    else
        result = 0;
    return result;
}
