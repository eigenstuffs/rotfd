extern "C" {
#include "Game/engine_record_buffers.h"
void fn_80025954(EngineRecordBufferItems*,int,int);
}
extern "C" void fn_80025898(EngineRecordBufferItems*self,int capacity){
 if(capacity<self->count)fn_80025954(self,capacity,0);
 else{
  if(capacity){
   if(self->items)self->items=(EngineRecordBufferItem*)fn_8028FAF4(lbl_8028F698,self->items,self->capacity*24,capacity*24);
   else self->items=(EngineRecordBufferItem*)fn_8028FF24(lbl_8028F698,capacity*24);
  }else if(self->items){
   fn_8028FD50(lbl_8028F698,self->items,self->capacity*24);
   self->items=0;
  }
  self->capacity=capacity;
 }
}
