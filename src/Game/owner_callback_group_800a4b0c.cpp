#include "Game/owner_callback_factory_views.h"
extern "C" void fn_800A4B0C(OwnerFactoryAgent*self){
OwnerFactoryCallback*p0=(OwnerFactoryCallback*)fn_801EFA1C(lbl_801EF5C8,sizeof(OwnerFactoryCallback),lbl_8029EAD8,lbl_8029EAE8,72,4);if(p0)p0=fn_800A3978(p0,self);self->callbacks[0]=p0;
OwnerFactoryCallback*p1=(OwnerFactoryCallback*)fn_801EFA1C(lbl_801EF5C8,sizeof(OwnerFactoryCallback),lbl_8029EAD8,lbl_8029EAE8,73,4);if(p1)p1=fn_800A3AD4(p1,self);self->callbacks[1]=p1;
OwnerFactoryCallback*p2=(OwnerFactoryCallback*)fn_801EFA1C(lbl_801EF5C8,sizeof(OwnerFactoryCallback),lbl_8029EAD8,lbl_8029EAE8,74,4);if(p2)p2=fn_800A3C74(p2,self);self->callbacks[2]=p2;
OwnerFactoryCallback*p3=(OwnerFactoryCallback*)fn_801EFA1C(lbl_801EF5C8,sizeof(OwnerFactoryCallback),lbl_8029EAD8,lbl_8029EAE8,75,4);if(p3)p3=fn_800A3BA4(p3,self);self->callbacks[3]=p3;
fn_8007D8EC(&self->controller,self->callbacks);self->controller.configure(4);
}
