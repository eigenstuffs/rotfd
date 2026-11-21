#include "Game/engine_owner_lifecycle.h"

static inline void destroyHandle(OwnerLifecycleHandle *self)
{
    if (self)
        __dt__15Handle_801F7F10Fv(self, 0);
}

static inline void destroyWrapped(OwnerLifecycleWrapped *self)
{
    if (self)
        destroyHandle(&self->handle);
}

OwnerLifecycleRecord *fn_8020B860(OwnerLifecycleRecord *self, int deleting)
{
    if (self) {
        destroyWrapped(&self->third);
        destroyWrapped(&self->second);
        destroyWrapped(&self->first);
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
