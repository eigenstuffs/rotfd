#include "Game/callback_state_adapters_internal.h"
extern "C" void fn_802525F0(CallbackAdapterIndexOwner*self){
    if(lbl_801E9D24.recordOwner){
        if(self->index!=-1){
            int old=self->index;
            fn_80252DE0(lbl_801E9D24.recordOwner,&old);
        }
        int result;
        fn_80252E1C(&result,lbl_801E9D24.recordOwner,self->key);
        self->index=result;
    }
    else self->index=-1;
}
