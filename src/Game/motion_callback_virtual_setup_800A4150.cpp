// Bounded native MI setup; original fulltable and destructor remain unowned.
#include "Game/motion_forwarding.h"
struct FactoryCallback{void*table;unsigned long unknown04;void*owner;};
struct MotionOwnerPrimaryView{unsigned long unknown0[2];virtual~MotionOwnerPrimaryView();char unknown0C[0x30C];};
struct MotionCallbackControllerView{virtual~MotionCallbackControllerView();virtual void setup();virtual void configure(int);virtual void reset();char unknown04[0xDC];};
struct Object_800A402C:MotionOwnerPrimaryView,MotionCallbackControllerView{virtual void setup();virtual~Object_800A402C();FactoryCallback**callbacks;};
typedef char CheckPrimary[(sizeof(MotionOwnerPrimaryView)==0x318)?1:-1];typedef char CheckSecondary[(sizeof(MotionCallbackControllerView)==0xE0)?1:-1];typedef char CheckOwner[(sizeof(Object_800A402C)==0x3FC)?1:-1];
extern "C"{extern unsigned char lbl_801EF5C8[];extern const char lbl_8029E9C0[],lbl_8029E9D0[];void*fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);void fn_8007D8EC(MotionCallbackControllerView*,FactoryCallback**);void fn_8007D6A0(MotionCallbackControllerView*,int);void fn_8009DBEC(Object_800A402C*);
FactoryCallback*fn_800A4334(FactoryCallback*,Object_800A402C*);
FactoryCallback*fn_800A4490(FactoryCallback*,Object_800A402C*);
FactoryCallback*fn_800A4630(FactoryCallback*,Object_800A402C*);
FactoryCallback*fn_800A4560(FactoryCallback*,Object_800A402C*);
}
void Object_800A402C::setup(){Object_800A402C*self=this;
FactoryCallback*p0=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,sizeof(FactoryCallback),lbl_8029E9C0,lbl_8029E9D0,72,4);if(p0)p0=fn_800A4334(p0,self);self->callbacks[0]=p0;
FactoryCallback*p1=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,sizeof(FactoryCallback),lbl_8029E9C0,lbl_8029E9D0,73,4);if(p1)p1=fn_800A4490(p1,self);self->callbacks[1]=p1;
FactoryCallback*p2=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,sizeof(FactoryCallback),lbl_8029E9C0,lbl_8029E9D0,74,4);if(p2)p2=fn_800A4630(p2,self);self->callbacks[2]=p2;
FactoryCallback*p3=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,sizeof(FactoryCallback),lbl_8029E9C0,lbl_8029E9D0,75,4);if(p3)p3=fn_800A4560(p3,self);self->callbacks[3]=p3;
fn_8007D8EC(&static_cast<MotionCallbackControllerView&>(*self),self->callbacks);configure(4);}
extern "C"void fn_800A42AC(Object_800A402C*self){fn_8009DBEC(self);fn_8007D6A0(&static_cast<MotionCallbackControllerView&>(*self),0);}
extern "C"void fn_800A42E4(ForwardActor*self,float delta){fn_8009DF78(self,delta);}
extern "C"void fn_800A4304(ForwardActor*self,const ForwardVector*first,const ForwardVector*second,float delta){fn_8009E640(self,first,second,delta);}
