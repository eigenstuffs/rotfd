#include "Game/engine_owner_small.h"

void fn_8021C504(struct EngineOwnerSmallChoice* self)
{
    if (self->active) {
        if (self->selected == 1)
            fn_8021C248(self);
        else if (self->selected == 2)
            fn_8021C030(self);
    } else {
        fn_8021B860(self);
    }
}
