#include "Game/early_actor_state_transition_views.h"
extern "C" void fn_800865A4(StateOwner*self,double delta){fn_80092DAC(self->actor,delta);unsigned char value=0;fn_800B7214(lbl_801E9D24.system,3,&value,0);if(fn_8025E9FC(self->controller,0x6E)||!value)fn_8007D6A0(&self->actor->record,fn_80092844(self->actor));else if(lbl_801E9D24.system->flag)fn_8007D6A0(&self->actor->record,0x30);}
