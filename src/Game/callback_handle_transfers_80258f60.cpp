#include "Game/callback_handle_transfers_internal.h"
extern "C" signed char fn_80258F60(CallbackTransferOwner*self) {
 if(!fn_80259F0C(self))return 0;
 if(fn_801F7EB8(&self->handle80))resolveRelated(self->handle80)->slot1C();
 return 1;
}
