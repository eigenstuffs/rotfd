#include "Game/callback_typed_assignment_internal.h"
extern "C" void fn_8025A48C(CallbackAssignmentOwner*self){
    fn_8025885C(self);
    if(self->flags&1ULL){
        CallbackHandleWord result;
        fn_801B52EC(&result,lbl_801E9D24.manager,lbl_802AEBD8);
        {
            CallbackHandleCopy temp(result);
            assignHandle(self->handle70,temp);
        }
        self->flags|=0x400000ULL;
        __dt__15Handle_801F7F10Fv(&result,-1);
    }
}
