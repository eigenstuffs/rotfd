#include "resource_slot_pool_internal.h"
struct SlotCallbackView : SlotManager {
    WorldCurveArray<ResetHandle2> extra;
    int first(){return limit==0 ? -1 : fn_80207B94(&occupied,1,0);}
    SlotRecord& recordAt(int i){SlotRecord* base=data;return base[i];}
    int next(int i){return i+1>=limit?-1:fn_80207B94(&occupied,1,i+1);}
};
extern "C" void fn_801E6D24(SlotCallbackView*self){
    int record=self->first();
    while(record>=0){
        for(int i=0;i<self->recordAt(record).slots.count;++i)
            self->recordAt(record).slots.data[i].get()->slot1C();
        record=self->next(record);
    }
    for(record=0;record<self->extra.count;++record)self->extra.data[record].get()->slot1C();
}
