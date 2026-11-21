#include "Game/callback_handle_transfers_internal.h"
struct NestedCallbackHandle {char unknown0[0x20];CallbackRelatedHandle handle20;};
struct NestedCallbackFlags {char unknown0[0xC];unsigned long flagsC;};
extern "C" void fn_8025529C(CallbackTransferOwner*self){
 if(!(self->flags&0x40000ULL)){
  fn_80213A18(resolveRelated(self->handle64));
  ((NestedCallbackFlags*)resolveRelated(((NestedCallbackHandle*)resolveRelated(self->handle58))->handle20))->flagsC&=~1UL;
 }
}
