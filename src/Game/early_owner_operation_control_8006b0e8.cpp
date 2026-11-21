#include "Game/early_owner_operation_control_views.h"
inline void finishOperation(OperationResource*resource){OperationResourceBase*base=resource;if(resource->mode==1)resource->slot12();base->slot11();}
extern "C" void fn_8006B0E8(OperationObject*self,OperationResource*resource){
OperationData*data=fn_8005EE10(resource);data->active=0;resource->flags&=~0x40000ULL;
if((resolveOperationActorTyped(((OperationActorResource*)resource)->owner)->flags&0x80) && data->notify)fn_8006B470(self,resolveOperation(resource->owner),3);
finishOperation(resource);
}
