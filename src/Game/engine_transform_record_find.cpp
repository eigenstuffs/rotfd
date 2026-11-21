#include "Game/engine_transform_records.h"

extern "C" int fn_8024BCA4(EngineTransformRecord* self, const EngineTransformHandle* target)
{
    for (int i = 0; i < self->count20; i++) {
        if (fn_801F7EB8(&self->items28[i])) {
            EngineTransformManager* manager = lbl_801E9D24.manager;
            EngineTransformNode* left = engineTransformResolveWithManager(manager, self->items28[i]);
            EngineTransformNode* right = engineTransformResolveWithManager(manager, *target);
            if (left == right)
                return i;
        }
    }
    return -1;
}
