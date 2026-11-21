#include "Game/owner_callback_factory_group_views.h"
extern "C" void fn_800AA838(FactoryGroupAgent6*self){
FactoryGroupCallback*p0=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,28,lbl_8029EED0,lbl_8029EEE0,71,4);if(p0)p0=fn_800AAC0C(p0,self);self->callbacks[0]=p0;
FactoryGroupCallback*p1=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,44,lbl_8029EED0,lbl_8029EEE0,72,4);if(p1)p1=fn_800AB190(p1,self);self->callbacks[1]=p1;
FactoryGroupCallback*p2=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,36,lbl_8029EED0,lbl_8029EEE0,73,4);if(p2)p2=fn_800AB9E4(p2,self);self->callbacks[2]=p2;
FactoryGroupCallback*p3=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,28,lbl_8029EED0,lbl_8029EEE0,74,4);if(p3)p3=fn_800AB470(p3,self);self->callbacks[3]=p3;
FactoryGroupCallback*p4=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,24,lbl_8029EED0,lbl_8029EEE0,75,4);if(p4)p4=fn_800AB804(p4,self);self->callbacks[4]=p4;
FactoryGroupCallback*p5=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,20,lbl_8029EED0,lbl_8029EEE0,76,4);if(p5)p5=fn_800ABC04(p5,self);self->callbacks[5]=p5;
fn_8007D8EC(&self->controller,self->callbacks);self->controller.configure(6);
}
