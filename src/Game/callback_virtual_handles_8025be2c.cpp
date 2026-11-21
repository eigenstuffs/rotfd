#include "Game/callback_virtual_handles_internal.h"
extern "C" void fn_8025BE2C(CallbackVirtualTarget*self,const CallbackVirtualHandle&value){
    if(fn_801F7EB8(self->slot78(-1))){
        CallbackVirtualTarget*object=resolveVirtual(*self->slot78(-1));
        fn_801F86C8(lbl_801E9D24.manager,&object->owned28,-1);
        object->owned28=value;
        fn_801F86C8(lbl_801E9D24.manager,&value,1);
    }
}
