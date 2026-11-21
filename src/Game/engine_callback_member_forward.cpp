#include "Game/engine_callback_member_activation.h"

extern "C" void fn_8025ED38(CallbackCycle*self,int key,CallbackSelector*selectors) {
 for(;selectors;selectors=selectors->next) {
  if(key==selectors->key) {
   for(CallbackMethodLink*link=selectors->methods;link;link=link->next) {
    CycleCallback callback=link->callback;
    DispatchNode *found=getOrCreate(self,callback);
    activate(self,found,key);
   }
   break;
  }
 }
}
