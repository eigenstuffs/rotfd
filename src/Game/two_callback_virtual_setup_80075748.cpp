// Distinct bounded native MI interface; original full table and destructor stay unowned.
struct FactoryCallback;
struct PrimaryOwnerVirtualView{unsigned long unknown0[2];virtual~PrimaryOwnerVirtualView();char unknown0C[0x15C];};
struct CallbackControllerVirtualView{virtual~CallbackControllerVirtualView();virtual void setup();virtual void configure(int);virtual void reset();char unknown04[0x2C];};
struct Object_80075618:PrimaryOwnerVirtualView,CallbackControllerVirtualView{virtual void setup();virtual~Object_80075618();FactoryCallback**callbacks;};
typedef char CheckPrimary[(sizeof(PrimaryOwnerVirtualView)==0x168)?1:-1];typedef char CheckSecondary[(sizeof(CallbackControllerVirtualView)==0x30)?1:-1];typedef char CheckOwner[(sizeof(Object_80075618)==0x19C)?1:-1];
extern "C"{extern unsigned char lbl_801EF5C8[];extern const char lbl_8029CC50[],lbl_8029CC60[];void*fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);FactoryCallback*fn_80075044(FactoryCallback*,Object_80075618*);FactoryCallback*fn_80075124(FactoryCallback*,Object_80075618*);void fn_8007D8EC(CallbackControllerVirtualView*,FactoryCallback**);signed char fn_8007DA74(CallbackControllerVirtualView*,float);}
void Object_80075618::setup(){Object_80075618*self=this;
FactoryCallback*p0=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029CC50,lbl_8029CC60,60,4);if(p0)p0=fn_80075044(p0,self);self->callbacks[0]=p0;
FactoryCallback*p1=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029CC50,lbl_8029CC60,61,4);if(p1)p1=fn_80075124(p1,self);self->callbacks[1]=p1;
fn_8007D8EC(&static_cast<CallbackControllerVirtualView&>(*self),self->callbacks);configure(2);}
extern "C" void fn_8007581C(){}
extern "C" void fn_80075820(Object_80075618*self,float delta){fn_8007DA74(&static_cast<CallbackControllerVirtualView&>(*self),delta);}
