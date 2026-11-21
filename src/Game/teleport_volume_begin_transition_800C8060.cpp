// TeleportVolume begin-transition event handler (fn_800C8060).
// Notes: the parent handle and the target object use an index-first,
// if/return resolve (get()); the relink view (resolveRelated) keeps the
// separate registry reload of the original. ownerOf() is the inlined form of
// the out-of-line getter at 0x8005E9A0; its handle-pointer argument is a
// reference to the caller's local, which gives the original register choice.
// setReference34() makes the Handle_80020834 conversion temporary an
// inline-time local (original stack slot 0x8). The callback descriptors are
// read from the shared pool lbl_802C1150; only the switch table is owned.
typedef unsigned long u32;typedef unsigned long long u64;
struct Object;struct Registry;struct BindingState;struct State;
struct Globals{char unknown[0x118];Registry*registry;char unknown11C[0x20];BindingState*binding;char unknown140[0x24];State*state;};
extern "C"{extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_801F7F10{
 union{u32 value;struct{signed long generation:8;signed long index:24;}bits;};
 Handle_801F7F10();~Handle_801F7F10();Object*resolve()const;Object*resolveRelated()const;Object*get()const;
 static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
extern "C" void fn_801F86C8(Registry*,const Handle_801F7F10*,int);
struct Handle_80020478:Handle_801F7F10{
 Handle_80020478(){value=0;}~Handle_80020478(){}
 Handle_80020478(const Handle_801F7F10&o){value=o.value;fn_801F86C8(lbl_801E9D24.registry,&o,1);}
 Handle_80020478(const Handle_80020478&o){value=o.value;fn_801F86C8(lbl_801E9D24.registry,&o,1);}
};
struct Handle_80020834:Handle_80020478{
 Handle_80020834(){value=0;}~Handle_80020834(){}
 Handle_80020834(const Handle_80020834&o){value=o.value;fn_801F86C8(lbl_801E9D24.registry,&o,1);}
 Handle_80020834(const Handle_801F7F10&o){value=o.value;fn_801F86C8(lbl_801E9D24.registry,&o,1);}
 Handle_80020834&operator=(const Handle_80020834&o){fn_801F86C8(lbl_801E9D24.registry,this,-1);value=o.value;fn_801F86C8(lbl_801E9D24.registry,&o,1);return *this;}
};
struct Handle_8002B67C:Handle_801F7F10{
 Handle_8002B67C(const Handle_801F7F10&o){value=o.value;fn_801F86C8(lbl_801E9D24.registry,&o,1);}~Handle_8002B67C(){}
};
struct Vec3{float x,y,z;void set(float a,float b,float c){x=a;y=b;z=c;}Vec3&operator=(const Vec3&o){x=o.x;y=o.y;z=o.z;return *this;}};
struct Prefix{u32 name;Handle_80020478 identity;};
struct VirtualPrefix:Prefix{
 virtual void slot08();
 virtual void slot0C();
 virtual void slot10();
 virtual void slot14();
 virtual void slot18();
 virtual void slot1C();
 virtual void slot20();
 virtual void slot24();
 virtual void slot28();
 virtual void slot2C();
 virtual void slot30();
 virtual void slot34();
 virtual void slot38();
 virtual void slot3C();
 virtual void slot40();
 virtual void slot44();
 virtual void slot48();
 virtual void slot4C();
 virtual void slot50();
 virtual void slot54();
 virtual void slot58();
 virtual void slot5C();
 virtual void slot60();
 virtual void slot64();
 virtual void slot68();
 virtual void slot6C();
 virtual void slot70();
 virtual void slot74();
 virtual void slot78();
 virtual void slot7C();
 virtual void slot80();
 virtual void slot84();
 virtual void slot88();
 virtual void slot8C();
 virtual void slot90();
 virtual void slot94();
 virtual void slot98();
 virtual void slot9C(int,int);
};
struct Transform{char unknown[0x30];Vec3 position;};
struct Object:VirtualPrefix{
 char unknown0C[0x18];Handle_801F7F10 reference24;char unknown28[0xC];Handle_80020834 reference34;u64 flags;void setReference34(const Handle_80020478&h){reference34=h;}
 char unknown40[0x20];Handle_801F7F10 reference60;char unknown64[0xC];Handle_801F7F10 reference70;
 char unknown74[0x10];u32 field84;char unknown88[0x28];Handle_801F7F10*referenceB0;
 char unknownB4[0x70];Transform*transform124;u32 unknown128;Vec3 position12C;char unknown138[0x74];Handle_801F7F10 reference1AC;
 bool hasFlags(u64 mask)const{return (flags&mask)!=0;}
};
struct Entry{Object*object;u32 unknown[2];signed char generation;char padding[3];signed char getTag()const{return generation;}};
struct Registry{int size,capacity;Entry*entries;};
struct RelatedRegistry{int size,capacity;Entry*entries;};
inline Object*Handle_801F7F10::resolve()const{Entry*entry=&lbl_801E9D24.registry->entries[bits.index];return entry->generation==bits.generation?entry->object:0;}
inline Object*Handle_801F7F10::get()const{Registry*m=lbl_801E9D24.registry;int index=bits.index;int tag=m->entries[index].getTag();if(tag==bits.generation)return m->entries[index].object;return 0;}
inline Object*Handle_801F7F10::resolveRelated()const{Entry*entry=&((RelatedRegistry*)lbl_801E9D24.registry)->entries[bits.index];return entry->generation==bits.generation?entry->object:0;}
struct State{char unknown[0x2D];char active;};
struct BindingState{char unknown[0x1C];Handle_801F7F10*reference;};
struct Agent:VirtualPrefix{
 char unknown0C[0x1C];Handle_80020834 reference28;char unknown2C[0x44];Handle_801F7F10 reference70;char unknown74[8];Handle_801F7F10 reference7C;
 char unknown80[0x2C];signed char fieldAC,fieldAD;char paddingAE[2];u32 fieldB0,fieldB4;Object*target,*resource;
 inline const Handle_80020478&ownIdentity(){return identity;}
};
struct Event{char unknown[0x28];unsigned short flags;short index;};
typedef void(Object::*MemberFunction)();
struct CallbackPool{MemberFunction first[8];char firstJumpTable[28];MemberFunction second[5];char secondJumpTable[28];MemberFunction third[5];};
struct CameraState{char unknown[0x1DC];char active;};
extern "C"{
extern CallbackPool lbl_802C1150;extern int lbl_8037808C,lbl_80378090,lbl_80378094;extern const char lbl_802A27A8[];extern const int lbl_80378598;
void fn_8025EF34(Agent*,MemberFunction,int);void fn_8025EEB4(Agent*,MemberFunction);void fn_8025EB70(Agent*,MemberFunction);Event*fn_8025F074(Agent*,MemberFunction);
void fn_8025F4F4(Event*,int,const char*);void fn_8025F658(Event*,int);void fn_8025F694(Event*,int);void fn_8025F620(Event*,int);signed char fn_8025E9FC(Agent*,int);
Object*fn_801F7EB8(const Handle_801F7F10*);void fn_80059340(Object*,int);void fn_80057E40(Object*);void fn_80056434(Object*,int);void fn_80058CB8(Object*,int,Handle_80020834);void fn_80286058(Object*,int);
CameraState*fn_8007D074();void fn_800A8520(Object*,unsigned char,int);
inline Object*ownerOf(Handle_801F7F10*&h){
 Handle_8002B67C handle(*h);
 if(fn_801F7EB8(&handle)){
  h=handle.resolve()->referenceB0;
  if(fn_801F7EB8(h))return h->resolve();
 }
 return 0;
}
int fn_800C8060(Agent*self,int type,Event*event){
 CallbackPool*pool=&lbl_802C1150;int result=1;
 switch(type){
 case 0:fn_8025EF34(self,pool->second[0],-1);return 1;
 case 1:fn_8025EEB4(self,pool->second[1]);return 1;
 case 2:fn_8025EB70(self,pool->second[2]);return 1;
 case 3:if(event)return(signed char)((event->flags>>2)&1);{Event*f=fn_8025F074(self,pool->second[3]);if(f)return(signed char)((f->flags>>2)&1);}return 0;
 case 4:if(event)return(signed char)(event->flags&1);{Event*f=fn_8025F074(self,pool->second[4]);if(f)return(signed char)(f->flags&1);}return 0;
 case 5:return 1;case 6:if(event)return event->index;return -9999;
 }
 lbl_8037808C=0;lbl_80378090=0;lbl_80378094=-1;
 if(type==8||type==7)fn_8025F4F4(event,0,lbl_802A27A8);
 if(type==11&&event->index==-1)return 1;
 fn_8025F658(event,lbl_80378090);
 switch(type>=14?type+event->index*2:type){
 case 7:fn_8025F694(event,lbl_8037808C);break;
 case 8:break;
 case 14:result=fn_8025E9FC(self,0x8A);break;
 case 15:{
  self->slot7C();Handle_80020834 parent(Handle_80020834(self->reference28));
  if(parent.get()->hasFlags(0x02000000ULL)){
   if(!self->fieldAC&&!self->fieldAD)fn_80059340(self->target,0x99);
   const Handle_801F7F10*binding=lbl_801E9D24.binding->reference->resolve()->referenceB0;
   Handle_801F7F10*resource=&binding->resolveRelated()->reference70;
   self->resource=fn_801F7EB8(resource)?resource->resolve():0;
   lbl_801E9D24.state->active=0;
   if(fn_801F7EB8(&self->reference7C)){const Vec3&position=self->reference7C.resolve()->transform124->position;self->target->position12C.set(position.x,position.y,position.z);}
   if(self->fieldAD){
    if(fn_801F7EB8(&self->resource->reference1AC)){
     Object*object=self->resource->reference1AC.resolve();fn_80057E40(self->target);object->reference24.resolve()->slot38();
    }
    Handle_801F7F10*ref=lbl_801E9D24.binding->reference;Object*object=ownerOf(ref);
    object->field84=lbl_80378598;fn_80056434(self->target,lbl_80378598);fn_80058CB8(self->target,0x238C,Handle_80020834());fn_80286058(object,0x86);
   }
   CameraState*camera=fn_8007D074();camera->active=1;
   Object*object=self->target->reference60.get();fn_800A8520(object,(unsigned char)self->fieldAD,self->fieldAC);
   object->setReference34(Handle_80020478(self->ownIdentity()));self->slot9C(0,0);
  }else if(parent.get()->hasFlags(0x20000000ULL)){parent.get()->slot38();}
  break;
 }
 default:result=2;
 }
 fn_8025F620(event,lbl_80378090);return result;
}
}
