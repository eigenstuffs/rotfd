#include "Game/engine_transform_records.h"

extern "C" void fn_8024C510(EngineTransformRecord* self)
{
    for (int i = 0; i < self->count; i++) {
        EngineTransformNode* node = engineTransformResolve(self->items[i]);
        if (node)
            node->slot54();
    }
}
