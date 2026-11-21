#include "Game/callback_typed_assignment_internal.h"
extern "C" void fn_80255750(CallbackAssignmentOwner*self){
    if(self->flags&0x800ULL){
        CallbackHandleWord result;
        fn_801B52EC(&result,lbl_801E9D24.manager,lbl_802AEB70);
        {
            CallbackHandleCopy temp(result);
            assignHandle(self->handle64,temp);
        }
        __dt__15Handle_801F7F10Fv(&result,-1);
    }
}
