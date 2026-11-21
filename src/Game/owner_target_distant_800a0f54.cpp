#include "Game/owner_motion_control_views.h"
extern "C" const char lbl_8029E618[];
extern "C" void fn_800A0F54(MotionControlAction*self,float delta){if(!fn_8009F170(self->agent)){fn_801F9D68(lbl_801E9D24.diagnostics,lbl_8029E618);return;}float distance=self->agent->distance;if(fn_8009F684(self->agent)>distance)fn_8007D6A0(self->agent->controls,6);else{MotionControlVec2 v;fn_8009F3E8(self->agent,fn_8009F170(self->agent),&v);applyMotionControl(self,delta,MotionControlVec3(-v.x,lbl_80378E40,-v.y));}}
