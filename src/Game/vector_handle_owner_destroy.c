#include "Game/engine_vector_owner.h"

static inline void destroyHandle(EngineVectorOwnerHandle* self)
{
    if (self)
        __dt__15Handle_801F7F10Fv(self, 0);
}

static inline void destroyWrapped(EngineVectorOwnerWrapped* self)
{
    if (self)
        destroyHandle(&self->handle);
}

static inline void destroyRoot(EngineVectorOwner* self)
{
    if (self) {
        self->table = __vt__13Manipulator_Z;
        __dt__11Activable_ZFv(self, 0);
    }
}

static inline void destroyBase(EngineVectorOwner* self)
{
    if (self) {
        self->table = lbl_802EB090;
        destroyWrapped(&self->second);
        destroyWrapped(&self->first);
        destroyRoot(self);
    }
}

EngineVectorOwner* fn_8020CEA8(EngineVectorOwner* self, int deleting)
{
    if (self) {
        self->table = lbl_802EB040;
        destroyBase(self);
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
