#include "Game/early_selection_event_control_views.h"
extern "C"void fn_800E39F0(SelectionOwner*self){fn_80259008(self);fn_800E3094(resolveActor(self->actor),self);lbl_801E9D24.scene->current=self;resolveActor(self->related)->flags&=0xFFFFFFFF7E0001FFULL;resolveActor(self->related)->flags|=0x2000ULL;}
