#include "world_curve_arrays_internal.h"
extern "C" void fn_801E3F2C(CurveRecordArray<CurveRecord4C_802EA7D8>* self,int size,signed char keep) {
    int i;
    if(size>self->count) {
        if(size>self->capacity||!keep) storage(self,size);
        for(i=self->count;i<size;++i) new(&self->data[i]) CurveRecord4C_802EA7D8;
        self->count=size;
    } else if(size<self->count) {
        for(i=self->count-1;i>=size;--i) self->data[i].~CurveRecord4C_802EA7D8();
        if(keep) self->count=size;
        else {storage(self,size);self->count=size;}
    }
}
