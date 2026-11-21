#include "Game/early_distance_control_views.h"
extern "C" void fn_80063A30(DistanceGateController*self){float distance=fn_80066BC8(self->script,resolveDistanceGate(fn_8005E9A0()->owner));if(distance>self->threshold||self->mode==1){if(self->oneShot==1)self->active=1;fn_8025A244(self);}else if(self->mode==0){if(self->active==1||distance<=lbl_80378700)fn_8025A190(self);}}
