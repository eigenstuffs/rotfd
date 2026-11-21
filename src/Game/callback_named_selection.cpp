#include "Game/callback_typed_assignment_internal.h"
extern "C" {
    void fn_8025BBA8(void*);
    void fn_8025A3C8(CallbackAssignmentOwner*,const CallbackHandleWord&);
    extern char lbl_802AEBC8[],lbl_8037B518[8];
}
inline signed char callbackSelectEnabled(CallbackAssignmentOwner*self){
    if(self->flags&8ULL)return 1;
    return 0;
}
extern "C" void fn_802597A4(CallbackAssignmentOwner*self){
    fn_8025BBA8(self);
    if(callbackSelectEnabled(self)){
        if(self->flags&0x10ULL){
            CallbackHandleWord result;
            fn_801B52EC(&result,lbl_801E9D24.manager,lbl_802AEBC8);
            fn_8025A3C8(self,result);
            __dt__15Handle_801F7F10Fv(&result,-1);
        }else{
            CallbackHandleWord result;
            fn_801B52EC(&result,lbl_801E9D24.manager,lbl_8037B518);
            fn_8025A3C8(self,result);
            __dt__15Handle_801F7F10Fv(&result,-1);
        }
    }
}
