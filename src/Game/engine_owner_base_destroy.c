#include "Game/engine_owner_lifecycle.h"

OwnerLifecycleBase *fn_8020B774(OwnerLifecycleBase *self, int deleting)
{
    if (self) {
        self->table = &lbl_802EAFE0;
        fn_8020C5CC(self, 0);
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
