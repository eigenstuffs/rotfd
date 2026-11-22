#include "Game/owner_callback_array_setup_views.h"
extern "C" void slot1A4__13CRedJfishMoveFv(CallbackArrayOwner*self,void*context){
slot1A4__14CJellyfishMoveFv(self,context);
CallbackArrayEntry*p0=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029E0E8,lbl_8029E0F8,91,4);if(p0)p0=fn_80094AB4(p0,self,context);self->callbacks[5]=p0;
CallbackArrayEntry*p1=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029E0E8,lbl_8029E0F8,92,4);if(p1)p1=fn_80094DDC(p1,self,context);self->callbacks[6]=p1;
CallbackArrayEntry*p2=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029E0E8,lbl_8029E0F8,94,4);if(p2)p2=fn_80098048(p2,self,context);self->callbacks[7]=p2;
CallbackArrayEntry*p3=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029E0E8,lbl_8029E0F8,95,4);if(p3)p3=fn_800981B0(p3,self,context);self->callbacks[8]=p3;
self->controller.configure(9);
}
