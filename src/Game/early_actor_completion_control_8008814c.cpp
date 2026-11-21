#include "Game/early_actor_completion_control_views.h"
extern "C" void fn_8008814C(CompletionOwner*self,double delta){int phase=-1;switch(self->mode){case 0:phase=3;break;case 1:phase=2;break;case 2:phase=1;break;}fn_80092BF4(self->actor,phase,delta);int next=fn_80092844(self->actor);if(next!=0x19)fn_8007D6A0(&self->actor->record,next);fn_80092DAC(self->actor,delta);}
