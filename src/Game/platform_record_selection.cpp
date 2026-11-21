#include "Game/platform_record_selection_internal.h"
extern "C" PlatformRecordIndex fn_80283DE4(PlatformArrays_802EA884* self,float threshold) {
    int result=-1;
    for(int i=0;i<self->records.count;++i) {
        PlatformRecord18* entry=platformRecordAt(self,i);
        if(entry->status==0) {
            float age=self->value10-entry->value14;
            if(!(age<=threshold)) {
                result=i;
                threshold=age;
            }
        }
    }
    if(result!=-1)return PlatformRecordIndex(result);
    return PlatformRecordIndex();
}
extern "C" void fn_80283D5C(PlatformArrays_802EA884* self,short remaining) {
    while(remaining>0) {
        PlatformRecordIndex chosen=fn_80283DE4(self,self->value14);
        if(chosen.index==-1)break;
        PlatformRecord18* entry=&self->records.data[chosen.index];
        remaining-=short(entry->count0C+entry->count12);
        fn_8026EB34(self,entry,2);
    }
}
