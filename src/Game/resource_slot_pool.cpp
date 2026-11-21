#include "resource_slot_pool_internal.h"
extern "C" void fn_801E5C1C(SlotManager*self,int record,OwnerHandle*handle){
    int i=0;
    while(i<self->at(record).size()){
        if(same(self->data[record].slots.data[i],*handle)){
            self->data[record].occupied.clear(i);
            *handle=ResetHandle2();
            return;
        }
        ++i;
    }
}
extern "C" signed char fn_801E5D78(SlotManager*self,int record,OwnerHandle*handle){
    int i=self->at(record).vacant();
    if(i<0){*handle=ResetHandle2();return 0;}
    self->data[record].occupied.set(i);
    *handle=self->data[record].slot(i);
    return 1;
}
extern "C" void fn_801E5EA4(SlotManager*self,int record){
    --self->data[record].references;
    SlotRecord& entry=self->at(record);
    if(entry.references==0)self->release(record,&entry);
}
