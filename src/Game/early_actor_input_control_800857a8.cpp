#include "Game/early_actor_input_control_views.h"
extern "C" void fn_800857A8(InputMotionOwner*self,double delta){if(self->actor->hasFlags(0x8000000000ULL))fn_8007D6A0(&self->actor->record,0x2B);else{InputVector value(self->vector.x,game_vec3_zero.y,self->vector.z);value*=self->actor->scale;self->actor->acceleration+=value;fn_80092DAC(self->actor,delta);}}
