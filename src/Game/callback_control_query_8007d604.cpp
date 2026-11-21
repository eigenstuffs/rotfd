#include "Game/early_callback_controller_views.h"
extern "C" signed char fn_8007D604(EarlyCallbackController*self,int index){
 fn_8007DCF4(self,index);
 signed char result=0;
 if(self->callbacks[index]->exclusive){
  if(self->current==index)result=1;
 }else{
  if(self->active&(1ULL<<index))result=1;
 }
 return result;
}
