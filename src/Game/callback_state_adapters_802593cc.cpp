#include "Game/callback_state_adapters_internal.h"
extern "C" void fn_802593CC(CallbackAdapterOwner*self,const void*value){
    self->flags|=0x8000ULL;
    fn_802139D8(resolveAdapter(self->handle70));
    fn_8022F474(resolveAdapter(self->handle80),value);
}
extern "C" void fn_802594B4(CallbackAdapterOwner*self,const void*value){
    self->flags|=0x8000ULL;
    fn_802139D8(resolveAdapter(self->handle70));
    fn_8022F49C(resolveAdapter(self->handle80),value);
}
