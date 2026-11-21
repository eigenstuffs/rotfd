#include "Game/engine_range_allocate.h"

extern "C" RangeAllocateIndex fn_8020EADC(RangeAllocateOwner *self, float threshold)
{
    RangeAllocateRecord *record;
    int offset;
    int found = -1;
    int i;
    for (i = 0, offset = 0; i < self->count; offset += sizeof(RangeAllocateRecord), i++) {
        record = (RangeAllocateRecord *)((char *)self->records + offset);
        if (!record->state) {
            float age = self->stamp - record->stamp;
            if (!(age <= threshold)) {
                found = i;
                threshold = age;
            }
        }
    }
    if (found != -1)
        return RangeAllocateIndex(found);
    return RangeAllocateIndex();
}
