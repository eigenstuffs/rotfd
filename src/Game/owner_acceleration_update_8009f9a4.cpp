#include "Game/owner_resource_action_views.h"
extern "C" const float lbl_80378E34;
inline signed char accelerationHasFlag(const ResourceActionAgent*self,unsigned long long mask){return (self->flags&mask)!=0;}
extern "C" void fn_8009F9A4(ResourceActionAgent*self,float delta){
if(!(resolveResourceAction(*self->getHandle(0))->flags&0x10000)){
if(!accelerationHasFlag(self,0x8000000000ULL)){
float y=delta*(self->blend*(lbl_80378E34*self->magnitude));
self->accelX+=lbl_80378DD8;self->accelY+=y;self->accelZ+=lbl_80378DD8;
}else self->velocityY=lbl_80378DD8;
}}
