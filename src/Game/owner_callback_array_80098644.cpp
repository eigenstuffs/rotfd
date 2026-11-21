#include "Game/owner_callback_array_setup_views.h"
extern "C" void fn_80098644(CallbackArrayOwner*self,void*context){
fn_80098B18(self,context);
CallbackArrayEntry*p0=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029E1D8,lbl_8029E1E8,83,4);if(p0)p0=fn_80094AB4(p0,self,context);self->callbacks[5]=p0;
CallbackArrayEntry*p1=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029E1D8,lbl_8029E1E8,84,4);if(p1)p1=fn_80094DDC(p1,self,context);self->callbacks[6]=p1;
CallbackArrayEntry*p2=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029E1D8,lbl_8029E1E8,86,4);if(p2)p2=fn_80097560(p2,self,context);self->callbacks[7]=p2;
CallbackArrayEntry*p3=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029E1D8,lbl_8029E1E8,87,4);if(p3)p3=fn_800976C8(p3,self,context);self->callbacks[8]=p3;
self->controller.configure(9);
}
