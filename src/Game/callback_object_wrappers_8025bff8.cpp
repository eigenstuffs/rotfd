#include "Game/callback_object_wrappers_internal.h"
extern "C" void fn_8025BFF8(CallbackWrapperObject*self,unsigned long value){
    resolve(*self->slot78(-1))->word20=value;
}
