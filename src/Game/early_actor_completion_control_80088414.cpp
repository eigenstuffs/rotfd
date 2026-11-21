#include "Game/early_actor_completion_control_views.h"
extern "C" void fn_80088414(CompletionOwner*self,float delta){if(self->actor->hasFlags(0x8000000000ULL)||(self->actor->enabled40D&&self->actor->velocity.y<lbl_80378AF0))fn_8007D6A0(&self->actor->record,fn_80092844(self->actor));fn_80092BF4(self->actor,9,delta);fn_80092DAC(self->actor,delta);}
