#include "Game/callback_handle_transfers_internal.h"
extern "C" void fn_80259FB4(CallbackTransferOwner*self,const CallbackRelatedHandle&value) {
 fn_80200104(resolveRelated(value),&self->handle58);
 fn_80257D20(self,value);
 if(fn_801F7EB8(&self->handle70))fn_8020016C(resolveRelated(value),&self->handle70);
}
