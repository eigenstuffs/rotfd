#include "Game/engine_callback_member_activation.h"

extern "C" void fn_8025EF34(CallbackCycle*self,const CycleCallback &callback,int key) {
 DispatchNode *found=find(self,callback);
 if(!found) {
  u32 previous;
  if(lbl_80378088) {previous=lbl_80378090;fn_8025F620(lbl_80378088,previous);}
  found=fn_8028625C(self);
  found->callback=callback;
  (self->*callback)(7,found);
  found->next=self->head;
  self->head=found;
  if(lbl_80378088) {lbl_80378090=previous;fn_8025F658(lbl_80378088,previous);}
 }
 if(key==-1 || fn_8025F37C(found,key)) {
  if(!(found->flags&4)) {
   found->flags|=4;
   found->flags&=0xfffe;
   self->reset=1;
  }
 }
}
