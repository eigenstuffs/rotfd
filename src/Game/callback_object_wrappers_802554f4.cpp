#include "Game/callback_object_wrappers_internal.h"
extern "C" void fn_802554F4(CallbackWrapperObject*self){
    resolve(self->related)->slot40();
    self->slot74();
}
extern "C" void fn_80255588(CallbackWrapperObject*self){
    CallbackWrapperObject*object=resolve(self->related);
    object->state=1;
    fn_8020ED58(object);
    self->slot74();
}
