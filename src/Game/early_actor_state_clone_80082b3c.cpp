#include "Game/early_actor_completion_control_views.h"
extern "C" void fn_80082B3C(CompletionOwner*self){self->actor->enabled40D=0;self->actor->setFlags(0x1000000000ULL);self->actor->speed=lbl_80378D58;if(lbl_803776B8&&lbl_803776B8->second)fn_80068158(lbl_803776B8,self->actor->record.key);}
