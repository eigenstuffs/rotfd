#include "Game/early_owner_pointer_flag_views.h"
extern "C" void fn_8006CB18(PointerQuery*self,signed char state){
if(state==1){self->getResource()->flags|=0x1000000000000ULL;resolvePointer(*self->getHandle())->actorFlags|=0x1000ULL;}
else{self->getResource()->flags&=~0x1000000000000ULL;resolvePointer(*self->getHandle())->actorFlags&=~0x1000ULL;}
}
