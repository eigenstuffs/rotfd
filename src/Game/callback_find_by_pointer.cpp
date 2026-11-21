#include "Game/callback_cycle_internal.h"
typedef int (CallbackCycle::*CycleCallback)(int,DispatchNode*);
extern "C" DispatchNode *fn_8025F074(CallbackCycle *self,const CycleCallback &callback) {
 for(DispatchNode *node=self->head;node;node=node->next) {
  if(callback==node->callback)return node;
 }
 return 0;
}
