#include "Game/owner_callback_array_setup_views.h"
extern "C" void fn_8009D2DC(CallbackArrayOwner*self){
CallbackArrayEntry*p0=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E480,lbl_8029E490,102,4);if(p0)p0=fn_8009C230(p0,self);self->callbacks[0]=p0;
CallbackArrayEntry*p1=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E480,lbl_8029E490,103,4);if(p1)p1=fn_8009C63C(p1,self);self->callbacks[1]=p1;
CallbackArrayEntry*p2=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E480,lbl_8029E490,104,4);if(p2)p2=fn_8009C758(p2,self);self->callbacks[2]=p2;
CallbackArrayEntry*p3=(CallbackArrayEntry*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E480,lbl_8029E490,105,4);if(p3)p3=fn_8009CB78(p3,self);self->callbacks[3]=p3;
self->controller.configure(4);
}
