#include "Game/callback_handle_transfers_internal.h"
extern "C" signed char fn_80258F60(CallbackTransferOwner*self) {
 if(!slot1C__13MovingAgent_ZFv(self))return 0;
 if(fn_801F7EB8(&self->handle80))resolveRelated(self->handle80)->slot1C();
 return 1;
}
