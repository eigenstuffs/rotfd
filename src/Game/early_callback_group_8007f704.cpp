#include "Game/early_callback_factory_group_views.h"
extern "C" void configureCallbacks__15CProjectileMoveFv(EarlyFactoryAgent4*self){
EarlyFactoryCallback*p0=(EarlyFactoryCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029D558,lbl_8029D568,74,4);if(p0)p0=fn_800801F0(p0,self);self->callbacks[0]=p0;
EarlyFactoryCallback*p1=(EarlyFactoryCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029D558,lbl_8029D568,75,4);if(p1)p1=fn_80080850(p1,self);self->callbacks[1]=p1;
EarlyFactoryCallback*p2=(EarlyFactoryCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029D558,lbl_8029D568,76,4);if(p2)p2=fn_80080AD4(p2,self);self->callbacks[2]=p2;
EarlyFactoryCallback*p3=(EarlyFactoryCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029D558,lbl_8029D568,77,4);if(p3)p3=fn_80081124(p3,self);self->callbacks[3]=p3;
fn_8007D8EC(&self->controller,self->callbacks);self->controller.configure(4);
}
