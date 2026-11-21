#include "Game/early_selection_event_control_views.h"
extern "C"int fn_800370F8(SelectionOwner*self){SelectionActor*actor=resolveActor(self->actor);if(!actor->state){self->flags|=0x20000ULL;fn_8025795C(self,0x99,0);fn_80255D88(self,0x23,0xF,0,0);actor->stateTime=lbl_80378450;actor->active=1;actor->state=1;}return 1;}
