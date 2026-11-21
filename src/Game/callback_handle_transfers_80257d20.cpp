#include "Game/callback_handle_transfers_internal.h"
extern "C" void fn_80257D20(CallbackTransferOwner*self,const CallbackRelatedHandle&value) {
 if(fn_801F7EB8(&self->handle64))fn_801FFFCC(resolveRelated(value),&self->handle64);
 fn_8020009C(resolveRelated(value),&self->handle58);
}
