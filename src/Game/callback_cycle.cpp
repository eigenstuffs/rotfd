// Linked callback-cycle reset, traversal and selected-key lookup.
#include "Game/callback_cycle_internal.h"
inline DispatchNode *CallbackCycle::next(){
 if(reset)lbl_80378088=head;
 while(lbl_80378088){DispatchNode *n=lbl_80378088;unsigned short flags=n->flags;
  if((signed char)((flags>>2)&1) && !(flags&2))return n;
  lbl_80378088=n->next;
 }return 0;
}
extern "C" void fn_8025E910(CallbackCycle*self){
 for(DispatchNode *n=self->head;n;n=n->next)n->flags&=0xfffd;
 self->reset=0;lbl_80378088=self->head;self->state=1;fn_80286158(self);
 self->active=self->pending;self->activeTail=self->pendingTail;self->pending=0;self->pendingTail=0;
 DispatchNode *n;while((n=self->next())!=0)fn_8025F240(n,self);lbl_80378088=0;
}
extern "C" int fn_8025E9FC(CallbackCycle*self,int key){
 for(SelectedNode*n=self->active;n;n=n->next){if(key==n->key){fn_801F7914(&self->handle,n);self->time=n->time;self->key=n->key;return 1;}}return 0;
}
