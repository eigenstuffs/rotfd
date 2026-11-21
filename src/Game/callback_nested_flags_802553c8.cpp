#include "Game/callback_handle_transfers_internal.h"
struct NestedCallbackHandle {char unknown0[0x20];CallbackRelatedHandle handle20;};
struct NestedCallbackFlags {char unknown0[0xC];unsigned long flagsC;};
extern "C" void fn_802553C8(CallbackTransferOwner*self){
 if(!(self->flags&0x20000ULL)){
  fn_802139D8(resolveRelated(self->handle64));
  ((NestedCallbackFlags*)resolveRelated(((NestedCallbackHandle*)resolveRelated(self->handle58))->handle20))->flagsC|=1UL;
 }
}
