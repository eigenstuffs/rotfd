#include "Game/early_callback_controller_views.h"
extern "C" signed char fn_8007D6A0(EarlyCallbackController*self,int index){
 fn_8007DCF4(self,index);
 signed char result=0;
 if(self->callbacks[index]->exclusive){
  self->changing=1;
  if(self->current!=-1){
   if(index==self->current)goto completed;
   self->pending=index;
   self->callbacks[self->current]->stop();
   self->pending=-1;
  }
  self->previous=self->current;
  self->current=index;
  result=1;
 }else{
  unsigned long long mask=1ULL<<index;
  if(!(self->active&mask)){
   self->active|=mask;
   ++self->activeCount;
   result=1;
  }
 }
completed:
 if(result)self->callbacks[index]->start();
 if(self->callbacks[index]->exclusive)self->changing=0;
 return result;
}
