#include "Game/early_actor_transition_control_views.h"
extern "C" void fn_800A1678(TransitionControlOwner*self,float delta){TransitionControlBehavior*behavior=fn_8005EE10(resolveResource(self->actor->handle));if(behavior->active==1)fn_800699A8(behavior,0);else fn_800A4DF0(self,delta);}
