#include "Game/callback_return_dispatch_internal.h"
struct ReturnFallbackOwner:DispatchCallbackOwner {
    CallbackRelatedHandle handle64;
};
extern "C" void fn_8023297C(void*,const DispatchHandleCopy*,int,int);
extern "C" void fn_8025795C(ReturnFallbackOwner*self,int index,void*argument){
    DispatchHandleCopy temp(fn_80257B70(self,index));
    if(!fn_801F7EB8((const CallbackRelatedHandle*)&temp))return;
    if(fn_801F7EB8(&self->handle60)){
        ((DispatchCallbackTarget*)resolveRelated(self->handle60))->slot30(&temp,0,argument);
    }
    else if(fn_801F7EB8(&self->handle64)){
        fn_8023297C(resolveRelated(self->handle64),&temp,0,1);
    }
}
