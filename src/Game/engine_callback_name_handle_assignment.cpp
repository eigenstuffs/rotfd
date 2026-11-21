#include "Game/engine_callback_name_handle_assignment.h"

typedef unsigned long u32;
struct Handle_801F7F10 {u32 value;Handle_801F7F10();~Handle_801F7F10();};
struct CallbackNameManager;
struct CallbackNameGlobals {char unknown[0x118];CallbackNameManager*manager;};
struct CallbackNameValue {u32 value;CallbackNameValue(const char*);};
extern "C" {extern CallbackNameGlobals lbl_801E9D24;extern const char lbl_802AEC58[];u32 fn_801F948C(void*,const char*);Handle_801F7F10 fn_801B550C(CallbackNameManager*,const CallbackNameValue&,const CallbackNameValue&);void fn_801F86C8(CallbackNameManager*,const void*,short);void fn_8025E5CC(void*);}
inline CallbackNameValue::CallbackNameValue(const char*s){value=fn_801F948C(this,s);}
// Two observed initialization layers precede the acquired Handle copy.
struct CallbackNameZero1:Handle_801F7F10 {CallbackNameZero1(){value=0;}};
struct CallbackNameZero2:CallbackNameZero1 {CallbackNameZero2(){value=0;}};
struct CallbackNameCopy:CallbackNameZero2 {CallbackNameCopy(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct CallbackNameStoredHandle {u32 value;CallbackNameStoredHandle&operator=(const CallbackNameCopy&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
struct CallbackNameHandleOwner {char unknown[0x6C];CallbackNameStoredHandle handle;};
extern "C" void fn_8025D6C4(CallbackNameHandleOwner* self) {
    fn_8025E5CC(self);
    self->handle = CallbackNameCopy(fn_801B550C(
        lbl_801E9D24.manager, CallbackNameValue(lbl_802AEC58),
        CallbackNameValue(lbl_802AEC58)));
}
