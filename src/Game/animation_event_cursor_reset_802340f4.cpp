#include "Game/animation_event_cursor_reset_802340f4.h"

extern "C" void fn_802340F4(void*self,AnimationEventState*state,void*target,float before,float after){
 AnimationEventRecord events[64];__construct_array(events,fn_801C6968,0,sizeof(AnimationEventRecord),64);int count=0;
 if(!(state->flags&0x10)){
  signed char again;
  do{
   count=0;if(state->age>after)state->age=after;
   if(!fn_801F694C(state->active,8,before,state->age,after,events,&count))break;
   again=0;
   for(int i=0;i<count;++i){AnimationEventRecord&event=events[i];
    if(event.command==12 && !(state->flags&2)){
     state->loopTime=event.time;state->flags|=2;if(before>state->loopTime)before=lbl_8037B1E0;again=1;
    }else if(event.command==13 && (state->flags&2)){
     if(state->flags&4){
      if(state->loopCount-- && state->loopCount==0){state->flags&=~6;float time=event.time;fn_80233944(self,state,target,before,time,after);before=time;}
     }else{state->loopCount=(AnimationHalf)event.value;state->flags|=4;}
     again=1;
     if(state->flags&4){
      float eventTime=event.time;float remaining=state->age>=eventTime?state->age-eventTime:after-eventTime;
      state->age=eventTime;fn_80233944(self,state,target,before,state->age,after);
      before=state->loopTime;state->age=state->loopTime+remaining;
      state->resetAll();
     }
    }
   }
  }while(again);
 }
 fn_80233944(self,state,target,before,state->age,after);
}
