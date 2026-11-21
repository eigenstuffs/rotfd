#include "Game/early_actor_input_control_views.h"
extern "C" void fn_800850D0(InputOwner*self){InputResource*target=resolveInput(self->bound);fn_800C3BC8(target,self->controller->slot38());fn_80257490(self->controller);self->active=0;if(lbl_803776B8&&lbl_803776B8->first)fn_8006803C(lbl_803776B8,self->actor->record.key);self->level=100;self->mode=0;}
