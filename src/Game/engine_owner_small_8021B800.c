#include "Game/engine_owner_small.h"

void fn_8021B800(struct EngineOwnerSmallDispatch* self, void* input, signed char flag)
{
    if (flag)
        fn_8021BD28(self, self->records + self->selected * 0x90, 2, input);
    else
        fn_8021BD28(self, self->records + self->selected * 0x90, 1, input);
}
