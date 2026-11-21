#include "Game/callback_typed_assignment_internal.h"
extern "C" {
void fn_8025BBA8(void*);
extern char lbl_802AEBB8[];
}
struct DeepHandleLayer3:CallbackHandleLayer2 {
    DeepHandleLayer3() { word=0; }
};
struct DeepHandleLayer4:DeepHandleLayer3 {
    DeepHandleLayer4() { word=0; }
};
struct DeepHandleLayer5:DeepHandleLayer4 {
    DeepHandleLayer5() { word=0; }
};
struct DeepHandleCopy:DeepHandleLayer5 {
    DeepHandleCopy(const CallbackHandleWord&value) {
        word=value.word;
        fn_801F86C8(lbl_801E9D24.manager,&value,1);
    }
};
struct DeepHandleOwner {
    char unknown0[0x38];
    unsigned long long flags;
    char unknown40[0x40];
    CallbackHandleWord handle80;
};
inline void assignDeepHandle(CallbackHandleWord&target,const DeepHandleCopy&value) {
    fn_801F86C8(lbl_801E9D24.manager,&target,-1);
    target.word=value.word;
    fn_801F86C8(lbl_801E9D24.manager,&value,1);
}
extern "C" void fn_80259258(DeepHandleOwner*self) {
    fn_8025BBA8(self);
    if(self->flags&0x40ULL) {
        CallbackHandleWord result;
        fn_801B52EC(&result,lbl_801E9D24.manager,lbl_802AEBB8);
        {
            DeepHandleCopy temp(result);
            assignDeepHandle(self->handle80,temp);
        }
        __dt__15Handle_801F7F10Fv(&result,-1);
    }
}
