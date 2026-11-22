#include "Game/early_actor_transition_control_views.h"
extern "C" void slot38__9CTileMoveFf(TransitionControlActor*self,float delta){self->previousVelocity=self->velocity;self->velocity=game_vec3_zero;if(!fn_8007D604(self->controller168,5)&&(short)lbl_801E9D24.scene->status->count>0)fn_8007D6A0(self->controller168,5);fn_8007DA74(self->controller168,delta);}
