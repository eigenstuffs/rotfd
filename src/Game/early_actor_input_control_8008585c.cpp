#include "Game/early_actor_input_control_views.h"
extern "C" void fn_8008585C(InputMotionOwner*self){self->actor->speed=self->speed;if(lbl_803776B8&&lbl_803776B8->second)fn_80068158(lbl_803776B8,self->actor->record.key);fn_80255CBC(self->controller,0x7D,0);fn_80255CBC(self->controller,0x7E,0);fn_80255D88(self->controller,0x81,0xF,0,0);}
