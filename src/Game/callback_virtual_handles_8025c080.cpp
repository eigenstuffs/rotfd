#include "Game/callback_virtual_handles_internal.h"
extern "C" signed char fn_8025C080(CallbackVirtualTarget*self){
    if(!slot1C__12BaseObject_ZFv(self))return 0;
    return resolveVirtual(*self->slot78(-1))->slot1C();
}
