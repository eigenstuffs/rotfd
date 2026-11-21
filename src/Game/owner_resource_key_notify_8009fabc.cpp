#include "Game/owner_resource_action_views.h"
extern "C" signed char fn_8009FABC(ResourceActionAgent*self,int key){
if(self->enabled==1 && (key!=self->lastKey||self->state==14) && fn_8009C12C(self,key)){
fn_80257828(resolveResourceAction(self->owner),key,0x8D,0);self->lastKey=key;}
return 1;}
