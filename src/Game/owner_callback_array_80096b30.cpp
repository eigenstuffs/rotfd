#include "Game/owner_callback_array_setup_views.h"
extern "C" void slot1A4__15CGreenJfishMoveFv(CallbackArrayOwner*self,void*context){
slot1A4__14CJellyfishMoveFv(self,context);
CallbackArrayEntry*p0=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029DF18,lbl_8029DF28,89,4);if(p0)p0=fn_800957B0(p0,self,context);self->callbacks[6]=p0;
CallbackArrayEntry*p1=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029DF18,lbl_8029DF28,90,4);if(p1)p1=fn_800957B0(p1,self,context);self->callbacks[5]=p1;
CallbackArrayEntry*p2=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029DF18,lbl_8029DF28,92,4);if(p2)p2=fn_8009587C(p2,self,context);self->callbacks[7]=p2;
CallbackArrayEntry*p3=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029DF18,lbl_8029DF28,93,4);if(p3)p3=fn_80095BB4(p3,self,context);self->callbacks[8]=p3;
self->controller.configure(9);
}
