#include "Game/early_actor_completion_control_views.h"
extern "C" void fn_80087AB4(CompletionOwner*self){if(validCompletion(self->actor->related)==1)fn_8025795C(self->controller,0x7B,0);else fn_8025795C(self->controller,1,0);if(lbl_803776B8&&lbl_803776B8->first)fn_8006803C(lbl_803776B8,self->actor->record.key);}
