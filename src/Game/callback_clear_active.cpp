#include "Game/callback_cycle_internal.h"
typedef int (CallbackCycle::*CycleCallback)(int, DispatchNode *);
inline DispatchNode *find(CallbackCycle *self, CycleCallback callback) {
 for (DispatchNode *node=self->head;node;node=node->next) {
  if(callback == node->callback) return node;
 }
 return 0;
}
extern "C" void fn_8025EB70(CallbackCycle*self,CycleCallback callback) {
 DispatchNode *found=find(self,callback);
 if(found)found->flags &=0xfffe;
}
