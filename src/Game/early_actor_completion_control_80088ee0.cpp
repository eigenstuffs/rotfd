#include "Game/early_actor_completion_control_views.h"
extern "C" void fn_80088EE0(CompletionOwner*self){self->actor->enabled40B=0;lbl_801E9D24.feedback->feedback(0,0,0);self->actor->flags|=0x1000000000ULL;self->actor->speed=lbl_80378D58;if(lbl_803776B8&&lbl_803776B8->second)fn_80068158(lbl_803776B8,self->actor->record.key);}
