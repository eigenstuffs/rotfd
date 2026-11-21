#include "Game/callback_return_dispatch_internal.h"
extern "C" void fn_80257828(DispatchCallbackOwner*self,int index,void*first,void*second){
    if(!fn_801F7EB8(&self->handle60))return;
    DispatchHandleCopy temp(fn_80257B70(self,index));
    if(!fn_801F7EB8((const CallbackRelatedHandle*)&temp))return;
    ((DispatchCallbackTarget*)resolveRelated(self->handle60))->slot30(&temp,first,second);
}
