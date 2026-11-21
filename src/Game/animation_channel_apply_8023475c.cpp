#include "Game/animation_channel_apply_8023475c.h"

extern "C" void fn_8023475C(AnimationChannelOwner*self,int index,float delta){
 AnimationChannelState*state=&self->states[index];float before=state->age;state->age+=delta*state->weight;state->flags&=~1;AnimationChannelTarget*target=resolve(self->target);
 if(state->flags&8){
  float end=state->age;if(state->age>state->end){state->flags&=~8;end=state->end;}
  for(int i=0;i<state->active->count;++i){AnimationChannelRecord*record=&state->records[i];int idx=record->index;if(idx>=0&&idx<target->count){AnimationChannelTarget*actor=resolve(target->items[idx]);if(actor){int out;fn_801AED04(record,actor,0,&out,before,end,state->end);}}}
  if(!(state->flags&8)){state->age-=state->end;before=lbl_8037B1E0;}
 }
 if(state->flags&8)return;
 float duration=state->active->duration;if((float)__fabs(duration)<=lbl_8037B200)return;
 AnimationChannelCallback*callback=getCallback(self);
 if(state->age>duration&&!(state->flags&2)){
  if(state->active->flags&1){state->flags|=0x100;do{state->age-=duration;}while(state->age>duration);state->resetAll();}
  else{
   state->age=duration;fn_802340F4(self,state,target,before,duration);
   if(callback)callback->slot28(index);
   if(callback&&callback->slot24(index))return;
   AnimationChannelTwiceZeroHandle handle;fn_8023297C(self,&handle,index,0);return;
  }
 }
 fn_802340F4(self,state,target,before,duration);
 if((state->flags&0x100)&&callback){callback->slot28(index);state->resetAll();}
 state->flags&=~0x100;
}
