#include "Game/callback_typed_assignment_internal.h"
extern "C" void fn_8025A3C8(CallbackAssignmentOwner*self,const CallbackHandleWord&value){
    {
        CallbackHandleCopy temp(value);
        assignHandle(self->handle70,temp);
    }
    self->flags|=0x400000ULL;
}
