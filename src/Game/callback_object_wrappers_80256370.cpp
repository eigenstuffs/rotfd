#include "Game/callback_object_wrappers_internal.h"
extern "C" void fn_80256370(CallbackWrapperFlagPrefix*self){
    fn_80285E10(self);
    fn_8025EBF0(self,&self->key);
    self->flags&=~0x38000ULL;
}
