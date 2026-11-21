#include "Game/callback_object_wrappers_internal.h"
extern "C" void fn_802550CC(CallbackWrapperObject*self,int value){
    resolve(self->related)->slot48(value);
}
