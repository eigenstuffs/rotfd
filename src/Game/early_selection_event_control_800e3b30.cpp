#include "Game/early_selection_event_control_views.h"
extern "C"void fn_800E3B30(SelectionOwner*self){if(fn_8025E9FC(self,0x8F)){self->flags|=0x20000ULL;fn_8007D6A0((char*)resolveActor(self->actor)+0x1F8,1);fn_80286058(self,0x8F);}if(fn_8025E9FC(self,0xAC)){self->flags&=0xFFFFFFFFFFFDFFFFULL;fn_8007D6A0((char*)resolveActor(self->actor)+0x1F8,0);fn_80286058(self,0x8F);}}
