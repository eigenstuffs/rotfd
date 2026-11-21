#include "Game/owner_motion_control_views.h"
extern "C" {extern const char lbl_8029E5D0[];extern const float lbl_80378E48,lbl_80378E4C;extern float lbl_803780A0;}
inline void instantTargetMotion(MotionControlAction*self,const MotionControlVec3&v){self->agent->direction=v;fn_8009ED90(self->agent,v,lbl_80378E48/(lbl_803780A0*lbl_80378E4C));fn_800A4E30(self);}
extern "C" void fn_800A0D3C(MotionControlAction*self){if(!fn_8009F170(self->agent)){fn_801F9D68(lbl_801E9D24.diagnostics,lbl_8029E5D0);return;}fn_8009FABC(self->agent,0x8F);MotionControlVec2 v;fn_8009F3E8(self->agent,fn_8009F170(self->agent),&v);instantTargetMotion(self,MotionControlVec3(-v.x,lbl_80378E40,-v.y));}
