#include "Game/early_misc_event_control_views.h"
extern "C"void fn_80081270(MiscControlOwner*self){if(!self->actor->hasFlag(0x8000000000ULL))self->actor->velocity=MiscVector(lbl_80378AA8,lbl_80378AB0,lbl_80378AA8);else fn_8007D6A0(self->actor->record,0);}
