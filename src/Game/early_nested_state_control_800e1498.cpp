#include "Game/early_nested_state_control_views.h"
extern "C"void fn_800E1498(NestedOwner*self){fn_8025A0A4(self);lbl_801E9D24.scene->state->active=self;resolveIntermediate(self->owner)->property&=~0x40000UL;resolveNested(self->actor)->flags&=0xFFFFFFFF7E0001FFULL;resolveNested(self->actor)->slot77(self);self->flags|=0x20000ULL;}
