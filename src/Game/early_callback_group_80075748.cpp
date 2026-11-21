#include "Game/early_callback_factory_group_views.h"
extern "C" void fn_80075748(EarlyFactoryAgent2*self){
EarlyFactoryCallback*p0=(EarlyFactoryCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029CC50,lbl_8029CC60,60,4);if(p0)p0=fn_80075044(p0,self);self->callbacks[0]=p0;
EarlyFactoryCallback*p1=(EarlyFactoryCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029CC50,lbl_8029CC60,61,4);if(p1)p1=fn_80075124(p1,self);self->callbacks[1]=p1;
fn_8007D8EC(&self->controller,self->callbacks);self->controller.configure(2);
}
