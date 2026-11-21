#include "Game/callback_handle_transfers_internal.h"
extern "C" void fn_8025A0A4(CallbackTransferOwner*self,const CallbackRelatedHandle&value) {
 fn_80257E04(self,&value);
 if(fn_801F7EB8(&self->handle70)) {
  fn_802001D4(resolveRelated(value),&self->handle70,4);
  fn_8020009C(resolveRelated(value),&self->handle58);
 }
}
