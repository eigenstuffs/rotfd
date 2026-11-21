#include "Game/owner_motion_control_views.h"
struct GroundMotionFlagView{char unknown00[0x30];unsigned long long flags;char unknown38[0x10C];float velocityX,velocityY,velocityZ;};
inline signed char groundMotionFlag(const MotionControlAgent*self,unsigned long long mask){return (((const GroundMotionFlagView*)self)->flags&mask)?1:0;}
extern "C" void fn_800A11A0(MotionControlAction*self,float delta){if(groundMotionFlag(self->agent,0x8000000000ULL))fn_8007D6A0(self->agent->controls,0);else if(((const GroundMotionFlagView*)self->agent)->velocityY<lbl_80378E40)fn_8007D6A0(self->agent->controls,0x10);else fn_800A4DF0(self,delta);}
