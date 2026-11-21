#include "Game/callback_related_dispatch_internal.h"
extern "C" void fn_80257338(CallbackRelatedOwner*self){
    if(!(self->flags&0x40000ULL)&&fn_801F7EB8(&self->handle64))fn_80213A18(resolveRelated(self->handle64));
}
extern "C" void fn_802573E4(CallbackRelatedOwner*self){
    if(!(self->flags&0x20000ULL)&&fn_801F7EB8(&self->handle64))fn_802139D8(resolveRelated(self->handle64));
}
extern "C" void fn_80257490(CallbackRelatedOwner*self){
    if(fn_801F7EB8(&self->handle60))resolveRelated(self->handle60)->slot20(-1,1);
}
extern "C" void fn_80257528(CallbackRelatedOwner*self,int value){
    if(fn_801F7EB8(&self->handle60))resolveRelated(self->handle60)->slot20(value,1);
}
