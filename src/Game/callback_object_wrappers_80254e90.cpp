#include "Game/callback_object_wrappers_internal.h"
extern "C" void fn_80254E90(CallbackWrapperObject*self,const CallbackWrapperHandle&h){
    fn_801FFEFC(resolve(h),&self->related);
}
extern "C" void fn_80254F00(CallbackWrapperObject*self,const CallbackWrapperHandle&h){
    fn_801FFF64(resolve(h),&self->related);
}
