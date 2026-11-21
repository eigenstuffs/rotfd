#include "Game/callback_state_adapters_internal.h"
extern "C" int fn_80252430(CallbackAdapterReceiver*self,void*unused,void*target,char*pose){
    if(self->record->state<0)return 0;
    if(target){
        return fn_8026C094(target,pose+0x60,self->slot3C(),pose+0x1C,pose+0xA0);
    }
    return 1;
}
