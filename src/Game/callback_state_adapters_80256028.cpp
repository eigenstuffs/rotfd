#include "Game/callback_state_adapters_internal.h"
extern "C" void fn_80256028(CallbackAdapterOwner*self,int index,signed char enabled){
    CallbackAdapterTarget*object=resolveAdapter(resolveAdapter(self->handle58)->related20);
    unsigned long mask=0x20UL<<index;
    object->flagsC&=~mask;
    if(enabled)object->flagsC|=mask;
}
