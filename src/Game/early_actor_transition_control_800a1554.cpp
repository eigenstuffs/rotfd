#include "Game/early_actor_transition_control_views.h"
extern "C" void fn_800A1554(TransitionControlOwner*self,float delta){if(fn_8005EE10(resolveResource(self->actor->handle))->active==1)fn_8007D6A0(self->actor->controller318,self->actor->state);fn_800A4DF0(self,delta);}
