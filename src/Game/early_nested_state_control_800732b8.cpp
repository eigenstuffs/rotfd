#include "Game/early_nested_state_control_views.h"
extern "C"void fn_800732B8(NestedOwner*self){self->enabled98=0;resolveNested(self->actor)->flags|=0x81FFFE00ULL;resolveIntermediate(self->owner)->property|=0x40000;resolveNested(resolveIntermediate(self->owner)->related)->slot15(-1);}
