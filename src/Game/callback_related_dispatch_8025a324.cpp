#include "Game/callback_related_dispatch_internal.h"
extern "C" void fn_8025A324(CallbackRelatedOwner*self,void*value){
    fn_80257FF0(self,value);
    if(fn_801F7EB8(&self->handle70))resolveRelated(self->handle70)->slot84(value);
}
