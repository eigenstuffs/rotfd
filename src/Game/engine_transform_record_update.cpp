#include "Game/engine_transform_records.h"

extern "C" signed char fn_8024C708(EngineTransformRecord* self)
{
    int i;
    if (!slot1C__12BaseObject_ZFv(self))
        return 0;
    if (fn_801F7EB8(&self->single))
        engineTransformResolve(self->single)->slot1C();
    for (i = 0; i < self->count30; i++) {
        if (fn_801F7EB8(&self->items38[i]))
            engineTransformResolve(self->items38[i])->slot1C();
    }
    for (i = 0; i < self->count; i++)
        engineTransformResolve(self->items[i])->slot1C();
    return 1;
}
