// Bounded native MI setup; original fulltable and destructor remain unowned.
#include "Game/early_actor_transition_control_views.h"
struct FactoryGroupCallback{void*table;unsigned long unknown04;void*owner;};
struct ManyOwnerPrimaryView{unsigned long unknown0[2];virtual~ManyOwnerPrimaryView();char unknown0C[0x30C];};
struct ManyCallbackControllerView{virtual~ManyCallbackControllerView();virtual void setup();virtual void configure(int);virtual void reset();char unknown04[0xDC];};
struct Object_800A2EE0:ManyOwnerPrimaryView,ManyCallbackControllerView{virtual void setup();virtual~Object_800A2EE0();FactoryGroupCallback**callbacks;};
typedef char CheckPrimary[sizeof(ManyOwnerPrimaryView)==0x318?1:-1];typedef char CheckSecondary[sizeof(ManyCallbackControllerView)==0xE0?1:-1];typedef char CheckOwner[sizeof(Object_800A2EE0)==0x3FC?1:-1];
extern "C"{extern unsigned char lbl_801EF5C8[];extern const char lbl_8029E890[],lbl_8029E8A0[];void*fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);void fn_8007D8EC(ManyCallbackControllerView*,FactoryGroupCallback**);
FactoryGroupCallback*fn_8009FE50(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A0C88(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_8009FF74(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A063C(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A0D00(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A083C(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A09F0(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A0EDC(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A1068(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A1F70(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A2038(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A13C8(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A14D0(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A1600(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A1720(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A17B8(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A125C(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A1AE8(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A1B60(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A1CCC(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_800A1EA8(FactoryGroupCallback*,Object_800A2EE0*);
FactoryGroupCallback*fn_8009FFEC(FactoryGroupCallback*,Object_800A2EE0*);
}
void Object_800A2EE0::setup(){Object_800A2EE0*self=this;
FactoryGroupCallback*p0=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,74,4);if(p0)p0=fn_8009FE50(p0,self);self->callbacks[0]=p0;
FactoryGroupCallback*p1=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,75,4);if(p1)p1=fn_800A0C88(p1,self);self->callbacks[1]=p1;
FactoryGroupCallback*p2=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,76,4);if(p2)p2=fn_8009FF74(p2,self);self->callbacks[2]=p2;
FactoryGroupCallback*p3=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,77,4);if(p3)p3=fn_800A063C(p3,self);self->callbacks[3]=p3;
FactoryGroupCallback*p4=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,78,4);if(p4)p4=fn_800A0D00(p4,self);self->callbacks[4]=p4;
FactoryGroupCallback*p5=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,79,4);if(p5)p5=fn_800A083C(p5,self);self->callbacks[5]=p5;
FactoryGroupCallback*p6=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,80,4);if(p6)p6=fn_800A09F0(p6,self);self->callbacks[6]=p6;
FactoryGroupCallback*p7=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,81,4);if(p7)p7=fn_800A0EDC(p7,self);self->callbacks[7]=p7;
FactoryGroupCallback*p8=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,82,4);if(p8)p8=fn_800A1068(p8,self);self->callbacks[8]=p8;
FactoryGroupCallback*p9=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,83,4);if(p9)p9=fn_800A1F70(p9,self);self->callbacks[9]=p9;
FactoryGroupCallback*p10=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,84,4);if(p10)p10=fn_800A2038(p10,self);self->callbacks[10]=p10;
FactoryGroupCallback*p11=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,85,4);if(p11)p11=fn_800A13C8(p11,self);self->callbacks[11]=p11;
FactoryGroupCallback*p12=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,86,4);if(p12)p12=fn_800A14D0(p12,self);self->callbacks[12]=p12;
FactoryGroupCallback*p13=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,87,4);if(p13)p13=fn_800A1600(p13,self);self->callbacks[13]=p13;
FactoryGroupCallback*p14=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,88,4);if(p14)p14=fn_800A1720(p14,self);self->callbacks[14]=p14;
FactoryGroupCallback*p15=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,89,4);if(p15)p15=fn_800A17B8(p15,self);self->callbacks[15]=p15;
FactoryGroupCallback*p16=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,90,4);if(p16)p16=fn_800A125C(p16,self);self->callbacks[16]=p16;
FactoryGroupCallback*p17=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,91,4);if(p17)p17=fn_800A1AE8(p17,self);self->callbacks[17]=p17;
FactoryGroupCallback*p18=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,92,4);if(p18)p18=fn_800A1B60(p18,self);self->callbacks[18]=p18;
FactoryGroupCallback*p19=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,93,4);if(p19)p19=fn_800A1CCC(p19,self);self->callbacks[19]=p19;
FactoryGroupCallback*p20=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,94,4);if(p20)p20=fn_800A1EA8(p20,self);self->callbacks[20]=p20;
FactoryGroupCallback*p21=(FactoryGroupCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029E890,lbl_8029E8A0,95,4);if(p21)p21=fn_8009FFEC(p21,self);self->callbacks[21]=p21;
fn_8007D8EC(&static_cast<ManyCallbackControllerView&>(*self),self->callbacks);configure(22);
}

extern "C" void fn_800A3628(TransitionControlActor*self){fn_8009DBEC(self);if(!(resolveResource(self->handle)->flags&0x8000000000ULL))fn_8007D6A0(self->controller318,0);}

// Advance the inherited phase controller, then accumulate its local clock.
struct ActorPhaseClock_800A36D0 {
    unsigned char prefix[0x394];
    float elapsed;
};
extern "C" void fn_8009DF78(ActorPhaseClock_800A36D0*, float);
extern "C" void fn_800A36D0(ActorPhaseClock_800A36D0* self, float delta) {
    fn_8009DF78(self, delta);
    self->elapsed = delta + self->elapsed;
}

struct ForwardActor;struct ForwardVector;extern "C"void fn_8009E640(ForwardActor*,const ForwardVector*,const ForwardVector*,float);

extern "C" void fn_800A371C(ForwardActor* self,const ForwardVector* first,const ForwardVector* second,float delta){fn_8009E640(self,first,second,delta);}
