#include "Game/callback_typed_assignment_internal.h"
extern "C" void fn_80255140(CallbackAssignmentOwner*self,const CallbackHandleWord&value){
    CallbackHandleCopy temp(value);
    assignHandle(self->handle64,temp);
}
