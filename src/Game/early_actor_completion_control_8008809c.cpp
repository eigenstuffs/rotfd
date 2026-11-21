#include "Game/early_actor_completion_control_views.h"
extern "C" void fn_8008809C(CompletionOwner*self){self->mode=resolveCompletion(self->actor->related)->state3EC;fn_8025795C(self->controller,0x77,0);if(lbl_803776B8&&lbl_803776B8->first)fn_8006803C(lbl_803776B8,self->actor->record.key);}
