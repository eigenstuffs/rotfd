#include "Game/callback_state_adapters_internal.h"
extern "C" void fn_80258C74(CallbackAdapterOwner*self){
    CallbackAdapterTarget*object=resolveAdapter(self->handle80);
    if(self->flags&0x8000ULL){
        fn_8025A244(self);
        if(object->slot90()>=0)fn_80213A18(object);
        else fn_802139D8(object);
    }
    else fn_8025A190(self);
}
extern "C" void fn_80258D48(CallbackAdapterOwner*self){
    if(!(self->flags&0x10000ULL)){
        fn_8025A244(self);
        CallbackAdapterTarget*object=resolveAdapter(self->handle80);
        if(self->flags&0x8000ULL){
            if(object->slot90()<0)fn_802139D8(object);
            else fn_80213A18(object);
        }
    }
}
