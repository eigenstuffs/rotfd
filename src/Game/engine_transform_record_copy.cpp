#include "Game/engine_transform_records.h"

static inline EngineTransformGroup* getGroup(int index)
{
    return &lbl_801E9D24.groups->items[index];
}

extern "C" void fn_8024C5D4(EngineTransformRecord* self)
{
    EngineTransformGroup* group = getGroup(self->group);
    int i;
    for (i = 0; i < self->count20; i++) {
        EngineTransformManager* manager = lbl_801E9D24.manager;
        EngineTransformNode* output = engineTransformResolveWithManager(manager, self->items28[i]);
        if (output) {
            EngineTransformNode* input = engineTransformResolveWithManager(manager, group->items[i]);
            output->x = input->x;
            output->y = input->y;
            output->z = input->z;
            output->qx = input->qx;
            output->qy = input->qy;
            output->qz = input->qz;
            output->qw = input->qw;
            output->sx = input->sx;
            output->sy = input->sy;
            output->sz = input->sz;
            output->flags &= ~0x40000;
            output->flags |= 0x2000;
        }
    }
}
