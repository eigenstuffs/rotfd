#include "Game/engine_nullable_handle_forward.h"

extern "C" void fn_80255CBC(NullableForwardSelf*self,int argument,NullableForwardSource*source){
 if(source){NullableForwardZeroHandle&original=source->handle04;fn_8023B35C(lbl_801E9D24.manager158,&NullableForwardCopyHandle(original),self->index54,argument);}
 else fn_8023B35C(lbl_801E9D24.manager158,&self->handle58,self->index54,argument);
}
