#include "Game/engine_nullable_handle_pair.h"

extern "C" void fn_80255D88(NullablePairSelf*self,int event,unsigned int flags,NullablePairSource*first,NullablePairSource*second){
 if((flags&3)==0){fn_8023B418(lbl_801E9D24.manager158,&NullablePairTwoZeroHandle(),self->index54,event,flags,&NullablePairTwoZeroHandle());}
 else if(!first){
  if(second){NullablePairZeroHandle&from=second->handle();fn_8023B418(lbl_801E9D24.manager158,&self->handle58,self->index54,event,flags,&NullablePairCopyHandle(from));}
  else fn_8023B418(lbl_801E9D24.manager158,&self->handle58,self->index54,event,flags,&NullablePairTwoZeroHandle());
 }else{
  if(second){NullablePairZeroHandle&from=first->handle04;fn_8023B418(lbl_801E9D24.manager158,&NullablePairCopyHandle(from),self->index54,event,flags,&NullablePairCopyHandle(second->handle()));}
  else{NullablePairZeroHandle&from=first->handle04;fn_8023B418(lbl_801E9D24.manager158,&NullablePairCopyHandle(from),self->index54,event,flags,&NullablePairTwoZeroHandle());}
 }
}
