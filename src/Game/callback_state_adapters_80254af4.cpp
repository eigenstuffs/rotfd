#include "Game/callback_state_adapters_internal.h"
extern "C" void fn_80254AF4(CallbackAdapterOwner*self,const void*point,const void*orientation){
    fn_8023D120(resolveAdapter(self->handle58),point,orientation);
    fn_8023DE28(resolveAdapter(self->handle58));
}
extern "C" void fn_80254BB4(CallbackAdapterOwner*self,const void*point){
    fn_8023D100(resolveAdapter(self->handle58),point);
    fn_8023DE28(resolveAdapter(self->handle58));
}
