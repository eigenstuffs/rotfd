#include "Game/callback_virtual_handles_internal.h"
extern "C" void fn_8025A190(CallbackVirtualTarget*self){
    if(!(self->flags&0x40000ULL)){
        if(fn_801F7EB8(&self->handle70))fn_80213A18(resolveVirtual(self->handle70));
        fn_80257338(self);
    }
}
