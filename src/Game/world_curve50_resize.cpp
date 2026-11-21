#include "world_curve50_internal.h"
extern "C" void fn_801E4450(CurveRecordArray<CurveRecord50_802F15C0>* self,int size,signed char keep) {
    int i;
    if(size>self->count) {
        if(size>self->capacity||!keep) storage(self,size);
        for(i=self->count;i<size;++i) new(&self->data[i]) CurveRecord50_802F15C0;
        self->count=size;
    } else if(size<self->count) {
        for(i=self->count-1;i>=size;--i) self->data[i].~CurveRecord50_802F15C0();
        if(keep) self->count=size;
        else {storage(self,size);self->count=size;}
    }
}
