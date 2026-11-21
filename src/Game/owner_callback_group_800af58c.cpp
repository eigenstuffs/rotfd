#include "Game/owner_callback_factory_group_views.h"
extern "C" void fn_800AF58C(FactoryGroupAgent3*self){
FactoryGroupCallback*p0=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_802A01D0,lbl_802A01E0,88,4);if(p0)p0=fn_800AE3B4(p0,self);self->callbacks[0]=p0;
FactoryGroupCallback*p1=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_802A01D0,lbl_802A01E0,89,4);if(p1)p1=fn_800AE6F8(p1,self);self->callbacks[1]=p1;
FactoryGroupCallback*p2=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,16,lbl_802A01D0,lbl_802A01E0,90,4);if(p2)p2=fn_800AEEF4(p2,self);self->callbacks[2]=p2;
fn_8007D8EC(&self->controller,self->callbacks);self->controller.configure(3);
}
