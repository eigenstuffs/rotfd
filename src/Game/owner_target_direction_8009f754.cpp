#include "Game/owner_target_action_views.h"
inline TargetActionVec3 directionTargetAction(const TargetActionVec2&v,signed char reverse){if(!reverse)return TargetActionVec3(-v.x,lbl_80378DD8,-v.y);return TargetActionVec3(v.x,lbl_80378DD8,v.y);}

extern "C" void fn_8009F754(TargetActionAgent*self,TargetActionResource*target){if(!(resolveTargetAction(*self->getHandle(0))->flags&0x10000)){TargetActionVec2 v;fn_8009F3E8(self,target,&v);self->direction=directionTargetAction(v,self->reverse);}}
