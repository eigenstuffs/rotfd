#include "Game/owner_resource_action_views.h"
extern "C" signed char fn_8009FB80(ResourceActionAgent*self,int key){
if(fn_8009C12C(self,key)){fn_802575CC(resolveResourceAction(self->owner),key,0x8D,0);return 1;}
return 0;}
