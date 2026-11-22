/* Part of the original ComplexMove source: configureCallbacks and the members
 * after it, with the vtable, RTTI records and adjustor thunks that the
 * compiler emits for the class (key function: configureCallbacks).  The class
 * hierarchy comes from the original RTTI base lists; see
 * include/Game/move_classes.h. */
#include "Game/move_classes.h"
#include "Game/motion_forwarding.h"
struct FactoryCallback{void*table;unsigned long unknown04;void*owner;};
struct CComplexMoveFields {char unknown00[0x3F8];FactoryCallback**callbacks;};
static inline CComplexMoveFields*fields(CComplexMove*self){return reinterpret_cast<CComplexMoveFields*>(self);}
extern "C"{extern unsigned char lbl_801EF5C8[];extern const char lbl_8029EAD8[],lbl_8029EAE8[];void*fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);void fn_8007D8EC(CFSM*,FactoryCallback**);void fn_8007D6A0(CFSM*,int);void slot34__11CScriptMoveFv(CComplexMove*);
FactoryCallback*fn_800A3978(FactoryCallback*,CComplexMove*);
FactoryCallback*fn_800A3AD4(FactoryCallback*,CComplexMove*);
FactoryCallback*fn_800A3C74(FactoryCallback*,CComplexMove*);
FactoryCallback*fn_800A3BA4(FactoryCallback*,CComplexMove*);
}
void CComplexMove::configureCallbacks(){CComplexMove*self=this;
FactoryCallback*p0=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,sizeof(FactoryCallback),lbl_8029EAD8,lbl_8029EAE8,72,4);if(p0)p0=fn_800A3978(p0,self);fields(self)->callbacks[0]=p0;
FactoryCallback*p1=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,sizeof(FactoryCallback),lbl_8029EAD8,lbl_8029EAE8,73,4);if(p1)p1=fn_800A3AD4(p1,self);fields(self)->callbacks[1]=p1;
FactoryCallback*p2=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,sizeof(FactoryCallback),lbl_8029EAD8,lbl_8029EAE8,74,4);if(p2)p2=fn_800A3C74(p2,self);fields(self)->callbacks[2]=p2;
FactoryCallback*p3=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,sizeof(FactoryCallback),lbl_8029EAD8,lbl_8029EAE8,75,4);if(p3)p3=fn_800A3BA4(p3,self);fields(self)->callbacks[3]=p3;
fn_8007D8EC(&static_cast<CFSM&>(*self),fields(self)->callbacks);configure(4);}
extern "C"void slot34__12CComplexMoveFv(CComplexMove*self){slot34__11CScriptMoveFv(self);fn_8007D6A0(&static_cast<CFSM&>(*self),0);}
extern "C"void slot38__12CComplexMoveFf(ForwardActor*self,float delta){slot38__11CScriptMoveFf(self,delta);}
extern "C"void slot40__12CComplexMoveFPC4Vec3PC4Vec3PC4Vec3if(ForwardActor*self,const ForwardVector*first,const ForwardVector*second,float delta){slot40__11CScriptMoveFPC4Vec3PC4Vec3PC4Vec3if(self,first,second,delta);}
