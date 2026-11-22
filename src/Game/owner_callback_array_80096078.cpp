#include "Game/owner_callback_array_setup_views.h"
extern "C" void slot1A4__16CYellowJfishMoveFv(CallbackArrayOwner*self,void*context){
slot1A4__14CJellyfishMoveFv(self,context);
CallbackArrayEntry*p0=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029DE20,lbl_8029DE30,93,4);if(p0)p0=fn_80094AB4(p0,self,context);self->callbacks[5]=p0;
CallbackArrayEntry*p1=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029DE20,lbl_8029DE30,94,4);if(p1)p1=fn_80094DDC(p1,self,context);self->callbacks[6]=p1;
CallbackArrayEntry*p2=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029DE20,lbl_8029DE30,96,4);if(p2)p2=fn_80096694(p2,self,context);self->callbacks[8]=p2;
CallbackArrayEntry*p3=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,16,lbl_8029DE20,lbl_8029DE30,97,4);if(p3)p3=fn_8009652C(p3,self,context);self->callbacks[7]=p3;
self->controller.configure(9);
}
