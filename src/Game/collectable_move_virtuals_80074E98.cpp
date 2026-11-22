/* Part of the original CollectableMove source: configureCallbacks and the members
 * after it, with the vtable, RTTI records and adjustor thunks that the
 * compiler emits for the class (key function: configureCallbacks).  The class
 * hierarchy comes from the original RTTI base lists; see
 * include/Game/move_classes.h. */
#include "Game/move_classes.h"

/* Leading .rodata objects of this unit. */
extern "C" const char lbl_8029CB88[] = "Anonymous New";
extern "C" const char lbl_8029CB98[] = "CollectableMove.cpp";
struct FactoryCallback;
struct CCollectableMoveFields {char unknown00[0x1B0];FactoryCallback**callbacks;};
static inline CCollectableMoveFields*fields(CCollectableMove*self){return reinterpret_cast<CCollectableMoveFields*>(self);}
extern "C"{extern unsigned char lbl_801EF5C8[];void*fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);FactoryCallback*fn_80074468(FactoryCallback*,CCollectableMove*);FactoryCallback*fn_80074638(FactoryCallback*,CCollectableMove*);FactoryCallback*fn_800747D0(FactoryCallback*,CCollectableMove*);void fn_8007D8EC(CFSM*,FactoryCallback**);}
void CCollectableMove::configureCallbacks(){CCollectableMove*self=this;

FactoryCallback*p0=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,20,lbl_8029CB88,lbl_8029CB98,76,4);if(p0)p0=fn_80074468(p0,self);fields(self)->callbacks[0]=p0;
FactoryCallback*p1=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,28,lbl_8029CB88,lbl_8029CB98,77,4);if(p1)p1=fn_80074638(p1,self);fields(self)->callbacks[1]=p1;
FactoryCallback*p2=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,36,lbl_8029CB88,lbl_8029CB98,78,4);if(p2)p2=fn_800747D0(p2,self);fields(self)->callbacks[2]=p2;
fn_8007D8EC(&static_cast<CFSM&>(*self),fields(self)->callbacks);configure(3);
}
extern "C" void slot38__16CCollectableMoveFf(){}
struct Controller{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18(void*,void*,void*,void*,float);};struct Component{char opaque00[8];int state08;};struct Owner{char opaque00[0x168];Component component;};extern "C"{Controller*fn_8007DCF8(Component*);void slot40__12ObjectMove_ZFPC4Vec3PC4Vec3PC4Vec3if(Owner*,void*,const void*);}extern "C"void slot40__16CCollectableMoveFPC4Vec3PC4Vec3PC4Vec3if(Owner*self,void*a,void*b,void*c,void*d,float elapsed){if(self->component.state08>=0)fn_8007DCF8(&self->component)->v18(a,b,c,d,elapsed);else slot40__12ObjectMove_ZFPC4Vec3PC4Vec3PC4Vec3if(self,a,b);}

/* Objects of this unit ahead of the compiler RTTI data; defined after their
 * users so that the values are not folded into the code. */
extern "C" const float lbl_80378978 = 0.0f;
