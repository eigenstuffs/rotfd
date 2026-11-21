#include "Game/callback_related_dispatch_internal.h"
extern "C" void fn_80257AE8(CallbackRelatedOwner*self){
    if(fn_801F7EB8(&self->handle60))resolveRelated(self->handle60)->byte5E=0;
}
