#include "Game/early_callback_controller_views.h"
extern "C" signed char fn_8007DA74(EarlyCallbackController*self,float delta){
 int index;
 unsigned int updated=0;
 signed char result=0;
 if(self->current!=-1){self->callbacks[self->current]->update(delta);result=1;}
 for(index=0;index<self->count;++index){
  if(self->active&(1ULL<<index)){
   self->callbacks[index]->update(delta);
   ++updated;result=1;
   if(updated==self->activeCount)break;
  }
 }
 return result;
}
