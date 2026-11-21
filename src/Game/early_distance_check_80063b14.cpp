#include "Game/early_distance_control_views.h"
extern "C" void fn_80063B14(DistanceGateController*self){if(self->mode==0){float distance=fn_80066BC8(self->script,resolveDistanceGate(fn_8005E9A0()->owner));if(self->active==1||distance<=lbl_80378700)fn_8025A190(self);else if(distance>self->threshold)fn_8025A244(self);}}
