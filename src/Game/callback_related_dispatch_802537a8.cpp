#include "Game/callback_related_dispatch_internal.h"
extern "C" signed char fn_802537A8(CallbackRelatedOwner*self){
    if(!slot1C__12BaseObject_ZFv(self))return 0;
    if(fn_801F7EB8(&self->handle48))resolveRelated(self->handle48)->slot1C();
    return 1;
}
