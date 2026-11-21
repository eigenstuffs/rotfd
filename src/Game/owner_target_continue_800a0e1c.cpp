#include "Game/owner_motion_control_views.h"
extern "C" void fn_800A0E1C(MotionControlAction*self,float delta){float distance=self->agent->distance;if(fn_8009F684(self->agent)>distance)fn_8007D6A0(self->agent->controls,6);else applyMotionControl(self,delta,MotionControlVec3(self->agent->direction));}
