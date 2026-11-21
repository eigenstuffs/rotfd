#include "world_records_internal.h"
#include "world_curve_arrays_internal.h"
extern "C" {
void fn_801F7154(void*);
signed char fn_801E48EC(WorldRecordView* self,const OwnerHandle* handle){
    for(int i=0;i<self->records30.count;++i){
        WorldRecord1C& record=self->records30.data[i];
        if(record.flag0C){
            Activable_Z* object=record.handle10.get();
            if(object==handle->get())return 1;
        }
    }
    return 0;
}
short fn_801E49B4(WorldRecordView* self,const u32* name){
    for(int i=0;i<self->records18.count;++i){
        u32 key=((CurveRecord4C_802EA7D8*)self->records18.data)[i].unknown;
        if(key==*name)
            return ((CurveRecord4C_802EA7D8*)self->records18.data)[i].id;
    }
    return -1;
}
signed char fn_801E4A04(WorldRecordView* self){
    if(!self->BaseObject_Z::slot1C())return 0;
    int i;
    for(i=0;i<self->records30.count;++i)self->records30.data[i].handle10.get()->slot1C();
    for(i=0;i<self->records3C.count;++i){
        if(fn_801F7EB8(&self->records3C.data[i].handle08))self->records3C.data[i].handle08.get()->slot1C();
        if(fn_801F7EB8(&self->records3C.data[i].handle0C))self->records3C.data[i].handle0C.get()->slot1C();
        if(fn_801F7EB8(&self->records3C.data[i].handle10))self->records3C.data[i].handle10.get()->slot1C();
    }
    fn_801F7154(self->object54);
    return 1;
}
}
