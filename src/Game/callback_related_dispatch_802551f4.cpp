#include "Game/callback_related_dispatch_internal.h"
extern "C" signed char fn_802551F4(CallbackRelatedOwner*self){
    if(!slot1C__12BaseObject_ZFv(self))return 0;
    if(fn_801F7EB8(&self->handle64))resolveRelated(self->handle64)->slot1C();
    return 1;
}
