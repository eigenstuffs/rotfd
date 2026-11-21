#include "Game/engine_vector_ops.h"

extern "C" void fn_80239458(EngineVectorOwner* self)
{
    float a = fn_8028506C(self->angle), b = fn_80284FA8(self->angle);
    self->m00 = a * self->scaleX;
    self->m10 = b * self->scaleX;
    self->m01 = -b * self->scaleY;
    self->m11 = a * self->scaleY;
    if (self->flags & 1) {
        self->x = (self->centerX - lbl_8037B2F8 * (self->m00 + self->m10)) + lbl_8037B2F8;
        self->y = (self->centerY - lbl_8037B2F8 * (self->m01 + self->m11)) + lbl_8037B2F8;
    } else {
        self->x = (lbl_8037B2F8 + self->centerX) * -(self->m00 + self->m10) - lbl_8037B2F8;
        self->y = (lbl_8037B2F8 + self->centerY) * -(self->m01 + self->m11) - lbl_8037B2F8;
    }
}

extern "C" signed char fn_80239568(EngineVectorOwner* self)
{
    if (!slot1C__12BaseObject_ZFv(self))
        return 0;
    for (int i = 0; i < 2; i++) {
        if (fn_801F7EB8(&self->handles[i]))
            engineVectorResolve(self->handles[i])->slot1C();
    }
    return 1;
}

extern "C" EngineVectorOwner* fn_80239638(EngineVectorOwner* self, short deleting)
{
    if (self) {
        self->vptr = __vt__22BasisResource_802EBFD8;
        __destroy_arr(self->handles, __dt__15Handle_8003F47CFv, 4, 2);
        if (self) {
            self->vptr = __vt__17Resource_802E9E20;
            __dt__12BaseObject_ZFv(self, 0);
        }
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
