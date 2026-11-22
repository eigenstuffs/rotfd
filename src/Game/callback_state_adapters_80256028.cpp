#include "Game/callback_state_adapters_internal.h"
extern "C" void slot6C__7Agent_ZFv(CallbackAdapterOwner*self,int index,signed char enabled){
    CallbackAdapterTarget*object=resolveAdapter(resolveAdapter(self->handle58)->related20);
    unsigned long mask=0x20UL<<index;
    object->flagsC&=~mask;
    if(enabled)object->flagsC|=mask;
}
