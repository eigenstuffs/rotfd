#pragma fp_contract on
#include "Game/engine_motion_collect_apply.h"

extern "C" int fn_80221A0C(MotionCollectOwner* self, signed char clear,
                           void* context) {
    if (clear) {
        self->flags &= ~0x200000000ULL;
        self->linked = 0;
    } else {
        self->slot48(context, lbl_8037B0C0);
        MotionCollectLinked* linked = self->linked;
        MotionCollectOwner* target = resolveMotionCollect(
            lbl_801E9D24.handles->data[linked->index]);
        const MotionCollectMatrix* matrix = linked->matrix;
        MotionCollectPoint position = matrix->transform(self->first);
        MotionCollectPoint delta = position - matrix->transform(self->second);
        MotionCollectSphere sphere(
            *((MotionCollectResource*)resolveMotionCollect(self->resource))->sphere);
        sphere.center += position;
        MotionCollectResults results;
        if ((signed char)fn_80268918(target, &sphere, &results,
                                    0x00008FE000000002ULL, 0x68ULL)) return 0;

        self->flags &= ~0x100000000ULL;
        self->flags &= ~0x200000000ULL;
        MotionCollectContact contact;
        contact.linked = self->linked;
        contact.point = position;
        contact.flags2C = 0;
        contact.flags28 = 0;
        self->slot114(&contact, &delta, 0);
        MotionCollectPoint current = self->slotB0(0);
        self->slot100(target, &current, &current, &position, 0, lbl_8037B0C0);
        self->slotBC(&position, 0);
        self->result = current - position;
        self->slot50(context);
    }
    return 1;
}
