#include "Game/engine_owner_lifecycle.h"

static inline void destroyRoot(OwnerLifecycleObject *self)
{
    if (self) {
        self->table = __vt__13Manipulator_Z;
        __dt__11Activable_ZFv(self, 0);
    }
}

OwnerLifecycleObject *fn_8020CA08(OwnerLifecycleObject *self, int deleting)
{
    if (self) {
        self->table = lbl_802EB000;
        destroyRoot(self);
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
