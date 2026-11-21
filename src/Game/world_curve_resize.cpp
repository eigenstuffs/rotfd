#include "world_curve_arrays_internal.h"
extern "C" void fn_801E3AC4(CurveRecordArray<CurveRecord3C_802EA7E4>* self,int size,signed char keep) {
    int i;
    if(size>self->count) {
        if(size>self->capacity||!keep) storage(self,size);
        for(i=self->count;i<size;++i) new(&self->data[i]) CurveRecord3C_802EA7E4;
        self->count=size;
    } else if(size<self->count) {
        for(i=self->count-1;i>=size;--i) self->data[i].~CurveRecord3C_802EA7E4();
        if(keep) self->count=size;
        else {storage(self,size);self->count=size;}
    }
}
