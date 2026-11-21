// Bounded native MI setup and clamped control; original full vtable and destructor remain separate.
#include "Game/six_callback_native_motion_views.h"
struct FactoryGroupCallback{void*table;unsigned long unknown04;void*owner;};
struct SixOwnerPrimaryView{unsigned long unknown0[2];virtual~SixOwnerPrimaryView();char unknown0C[0x15C];};
struct SixCallbackControllerView{virtual~SixCallbackControllerView();virtual void setup();virtual void configure(int);virtual void reset();char unknown04[0x28];};
struct Object_800AA6E0:SixOwnerPrimaryView,SixCallbackControllerView{virtual void setup();virtual~Object_800AA6E0();unsigned long unknown194;FactoryGroupCallback**callbacks;};
typedef char CheckPrimary[sizeof(SixOwnerPrimaryView)==0x168?1:-1];typedef char CheckSecondary[sizeof(SixCallbackControllerView)==0x2C?1:-1];typedef char CheckOwner[sizeof(Object_800AA6E0)==0x19C?1:-1];
extern "C"{extern unsigned char lbl_801EF5C8[];extern const char lbl_8029EED0[],lbl_8029EEE0[];void*fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);void fn_8007D8EC(SixCallbackControllerView*,FactoryGroupCallback**);
FactoryGroupCallback*fn_800AAC0C(FactoryGroupCallback*,Object_800AA6E0*);
FactoryGroupCallback*fn_800AB190(FactoryGroupCallback*,Object_800AA6E0*);
FactoryGroupCallback*fn_800AB9E4(FactoryGroupCallback*,Object_800AA6E0*);
FactoryGroupCallback*fn_800AB470(FactoryGroupCallback*,Object_800AA6E0*);
FactoryGroupCallback*fn_800AB804(FactoryGroupCallback*,Object_800AA6E0*);
FactoryGroupCallback*fn_800ABC04(FactoryGroupCallback*,Object_800AA6E0*);
}
extern "C"void fn_800AABF8(){}

extern "C" void fn_800AAADC(ClampVectorActor*self,float delta,void*arg,const ClampVector*input,void*arg6,void*arg7){if(self->originActive){self->slot45(self->origin,0);self->originActive=0;}else{float center=self->getCenterHeight();float radius=self->getRadius();float value=input->y;if(value<center-radius)value=center-radius;else if(value>radius+center)value=radius+center;ClampVector position=*input;position.y=value;self->slot45(position,0);}if(self->state>=0)fn_8007DCF8(self->controller)->update(delta,arg,input,arg6,arg7);}

extern "C" void fn_800AAA1C(ClampVectorActor*self,float delta){self->previousVelocity=self->velocity;self->velocity=game_vec3_zero;if(!fn_8007D604(self->controller,5)&&(short)lbl_801E9D24.scene->status->count>0)fn_8007D6A0(self->controller,5);fn_8007DA74(self->controller,delta);}

void Object_800AA6E0::setup(){Object_800AA6E0*self=this;
FactoryGroupCallback*p0=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,28,lbl_8029EED0,lbl_8029EEE0,71,4);if(p0)p0=fn_800AAC0C(p0,self);self->callbacks[0]=p0;
FactoryGroupCallback*p1=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,44,lbl_8029EED0,lbl_8029EEE0,72,4);if(p1)p1=fn_800AB190(p1,self);self->callbacks[1]=p1;
FactoryGroupCallback*p2=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,36,lbl_8029EED0,lbl_8029EEE0,73,4);if(p2)p2=fn_800AB9E4(p2,self);self->callbacks[2]=p2;
FactoryGroupCallback*p3=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,28,lbl_8029EED0,lbl_8029EEE0,74,4);if(p3)p3=fn_800AB470(p3,self);self->callbacks[3]=p3;
FactoryGroupCallback*p4=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,24,lbl_8029EED0,lbl_8029EEE0,75,4);if(p4)p4=fn_800AB804(p4,self);self->callbacks[4]=p4;
FactoryGroupCallback*p5=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,20,lbl_8029EED0,lbl_8029EEE0,76,4);if(p5)p5=fn_800ABC04(p5,self);self->callbacks[5]=p5;
fn_8007D8EC(&static_cast<SixCallbackControllerView&>(*self),self->callbacks);configure(6);
}
