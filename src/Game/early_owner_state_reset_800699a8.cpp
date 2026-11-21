#include "Game/early_owner_state_reset_views.h"
extern "C" signed char fn_800699A8(ResetObject*self){
fn_80069CA8(self,resolveReset(self->getResource()->owner),0);
self->getResource()->flags|=0x40000ULL;
self->getResource()->flags&=~0x20000ULL;
fn_8025E8E0(self->getResource());
fn_8025ECB4(self->getResource());
self->getResource()->slot10();
return 1;
}
