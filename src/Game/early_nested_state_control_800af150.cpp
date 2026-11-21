#include "Game/early_nested_state_control_views.h"
extern "C"void fn_800AF150(NestedClearOwner*self){self->time=lbl_80379160;self->actor->flags&=~0x600ULL;resolveNested(*self->actor->slot37(0))->property&=~0x40000UL;NestedChild*child=resolveNested(self->actor->owner)->child;if(child){fn_80255678(child);child->flags&=~0x20000ULL;child->flags|=0x40000ULL;}}
