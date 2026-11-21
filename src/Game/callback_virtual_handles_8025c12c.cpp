#include "Game/callback_virtual_handles_internal.h"
extern "C" void fn_8025C12C(CallbackVirtualTarget*self){
    if(!(self->flags&0x40000ULL)){
        if(fn_801F7EB8(self->slot78(-1)))fn_80213A18(resolveVirtual(*self->slot78(-1)));
        fn_8025E8F8(self);
    }
}
extern "C" void fn_8025C208(CallbackVirtualTarget*self){
    if(!(self->flags&0x20000ULL)){
        if(fn_801F7EB8(self->slot78(-1)))fn_802139D8(resolveVirtual(*self->slot78(-1)));
        fn_8025E8E0(self);
    }
}
extern "C" void fn_8025C2E4(CallbackVirtualTarget*self){
    self->slot28(0);
    if(fn_801F7EB8(self->slot78(-1)))resolveVirtual(*self->slot78(-1))->slot34();
}
