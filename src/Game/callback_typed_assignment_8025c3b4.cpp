#include "Game/callback_typed_assignment_internal.h"
extern "C" void fn_8025C3B4(CallbackAssignmentVirtual*self){
    self->slot28(0);
    if(self->flags&0x400ULL){
        CallbackHandleWord result;
        fn_801B52EC(&result,lbl_801E9D24.manager,lbl_802AEC38);
        {
            CallbackHandleCopy temp(result);
            assignHandle(self->handle60,temp);
        }
        __dt__15Handle_801F7F10Fv(&result,-1);
    }
}
