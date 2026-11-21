#include "Game/engine_range_dispatch.h"

struct RangeDispatchIndex {
    int value;
    RangeDispatchIndex() {}
    RangeDispatchIndex(const RangeDispatchIndex &other): value(other.value) {}
};
extern "C" RangeDispatchIndex fn_8020EADC(RangeDispatchOwner *, float);

extern "C" void fn_8020E8B0(RangeDispatchOwner *self, short count)
{
    while (count > 0) {
        RangeDispatchIndex index = fn_8020EADC(self, self->threshold);
        if (index.value == -1)
            break;
        RangeDispatchRecord *record = &self->records.items[index.value];
        count -= (short)(record->first.count + record->second.count);
        fn_8020E938(self, record, 2);
    }
}
