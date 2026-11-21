#include "Game/early_callback_factory_group_views.h"
extern "C" void fn_80074E98(EarlyFactoryAgent3*self){
EarlyFactoryCallback*p0=(EarlyFactoryCallback*)fn_801EFA1C(lbl_801EF5C8,20,lbl_8029CB88,lbl_8029CB98,76,4);if(p0)p0=fn_80074468(p0,self);self->callbacks[0]=p0;
EarlyFactoryCallback*p1=(EarlyFactoryCallback*)fn_801EFA1C(lbl_801EF5C8,28,lbl_8029CB88,lbl_8029CB98,77,4);if(p1)p1=fn_80074638(p1,self);self->callbacks[1]=p1;
EarlyFactoryCallback*p2=(EarlyFactoryCallback*)fn_801EFA1C(lbl_801EF5C8,36,lbl_8029CB88,lbl_8029CB98,78,4);if(p2)p2=fn_800747D0(p2,self);self->callbacks[2]=p2;
fn_8007D8EC(&self->controller,self->callbacks);self->controller.configure(3);
}
