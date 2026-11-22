#include "Game/callback_related_dispatch_internal.h"
extern "C" signed char slot1C__13MovingAgent_ZFv(CallbackRelatedOwner*self){
    if(!fn_80257C78(self))return 0;
    if(fn_801F7EB8(&self->handle70))resolveRelated(self->handle70)->slot1C();
    return 1;
}
