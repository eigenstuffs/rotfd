#include "Game/early_callback_controller_views.h"
extern "C" signed char fn_8007D7F4(EarlyCallbackController*self,int index){
 fn_8007DCF4(self,index);
 signed char result=0;
 if(self->callbacks[index]->exclusive){
  if(self->current==index){self->current=-1;result=1;}
 }else{
  unsigned long long mask=1ULL<<index;
  if(self->active&mask){self->active&=~mask;--self->activeCount;result=1;}
 }
 if(result)self->callbacks[index]->stop();
 return result;
}
