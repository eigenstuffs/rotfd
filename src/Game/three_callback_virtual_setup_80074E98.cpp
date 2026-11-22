// Only the observed native virtual interface is claimed. Its generated
// 40-byte table and undefined destructor thunk remain unowned; normal native
// linking must omit them. The original full320-byte table and DT stay intact.
// Distinct bounded native MI interface; no original full-class claim.
struct FactoryCallback;
struct PrimaryOwnerVirtualView{unsigned long unknown0[2];virtual~PrimaryOwnerVirtualView();char unknown0C[0x15C];};
struct CallbackControllerVirtualView{virtual~CallbackControllerVirtualView();virtual void setup();virtual void configure(int);virtual void reset();char unknown04[0x2C];};
struct Object_80074D40:PrimaryOwnerVirtualView,CallbackControllerVirtualView{virtual void setup();virtual~Object_80074D40();float ownerPointAndValues[6];FactoryCallback**callbacks;};
typedef char CheckPrimary[(sizeof(PrimaryOwnerVirtualView)==0x168)?1:-1];
typedef char CheckSecondary[(sizeof(CallbackControllerVirtualView)==0x30)?1:-1];
typedef char CheckOwner[(sizeof(Object_80074D40)==0x1B4)?1:-1];
extern "C"{extern unsigned char lbl_801EF5C8[];extern const char lbl_8029CB88[],lbl_8029CB98[];void*fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);FactoryCallback*fn_80074468(FactoryCallback*,Object_80074D40*);FactoryCallback*fn_80074638(FactoryCallback*,Object_80074D40*);FactoryCallback*fn_800747D0(FactoryCallback*,Object_80074D40*);void fn_8007D8EC(CallbackControllerVirtualView*,FactoryCallback**);}
void Object_80074D40::setup(){Object_80074D40*self=this;

FactoryCallback*p0=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,20,lbl_8029CB88,lbl_8029CB98,76,4);if(p0)p0=fn_80074468(p0,self);self->callbacks[0]=p0;
FactoryCallback*p1=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,28,lbl_8029CB88,lbl_8029CB98,77,4);if(p1)p1=fn_80074638(p1,self);self->callbacks[1]=p1;
FactoryCallback*p2=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,36,lbl_8029CB88,lbl_8029CB98,78,4);if(p2)p2=fn_800747D0(p2,self);self->callbacks[2]=p2;
fn_8007D8EC(&static_cast<CallbackControllerVirtualView&>(*self),self->callbacks);configure(3);
}
extern "C" void fn_80074FB0(){}
struct Controller{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18(void*,void*,void*,void*,float);};struct Component{char opaque00[8];int state08;};struct Owner{char opaque00[0x168];Component component;};extern "C"{Controller*fn_8007DCF8(Component*);void fn_8021F568(Owner*,void*,const void*);}extern "C"void fn_80074FB4(Owner*self,void*a,void*b,void*c,void*d,float elapsed){if(self->component.state08>=0)fn_8007DCF8(&self->component)->v18(a,b,c,d,elapsed);else fn_8021F568(self,a,b);}
