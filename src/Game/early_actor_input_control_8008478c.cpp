#include "Game/early_actor_input_control_views.h"
extern "C" void fn_8008478C(InputOwner*self){if(self->actor->flags&0x8000000000ULL)fn_80257828(self->controller,0x20,0x76,0);else fn_80257828(self->controller,0x2A,0x76,0);if(lbl_803776B8&&lbl_803776B8->first)fn_8006803C(lbl_803776B8,self->actor->record.key);}
