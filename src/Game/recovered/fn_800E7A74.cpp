// Callback dispatch handler (fn_800E7A74); structure follows the matched sibling
// teleport_volume_begin_transition_800C8060.cpp (same handle/registry views).
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
 char unknown0C[0x1C];Handle_80020834 reference28;char unknown2C[0x44];Object*target;
};
struct Event{char unknown[0x28];unsigned short flags;short index;};
struct MemberFunction{u32 a,b,c;};
struct CallbackPool{char unknown00[0x70];MemberFunction second[5];};
// Five virtual-only member-function constants (this adjustment 0, slot 0x94, vtable offset 8)
// passed by the handler below.  They sit at 0x802C8F40, directly before its switch table, and
// are read through the data-pool base of the preceding functions (lbl_802C8ED0 + 0x70).
extern "C" MemberFunction lbl_802C8F40[5] = {
 { 0, 0x94, 8 },
 { 0, 0x94, 8 },
 { 0, 0x94, 8 },
 { 0, 0x94, 8 },
 { 0, 0x94, 8 },
};
extern "C"{
extern CallbackPool lbl_802C8ED0;extern int lbl_8037808C,lbl_80378090,lbl_80378094;extern const char lbl_802AB1E8[];
void fn_8025EF34(Agent*,MemberFunction,int);void fn_8025EEB4(Agent*,MemberFunction);void fn_8025EB70(Agent*,MemberFunction);Event*fn_8025F074(Agent*,MemberFunction);
void fn_8025F4F4(Event*,int,const char*);void fn_8025F658(Event*,int);void fn_8025F694(Event*,int);void fn_8025F620(Event*,int);signed char fn_8025E9FC(Agent*,int);
Object*fn_801F7EB8(const Handle_801F7F10*);void fn_80058CB8(Object*,int,Handle_80020834);void fn_80286058(Object*,int);void fn_8007D6A0(void*,int);
inline Object*ownerOf(Handle_801F7F10*h,Handle_801F7F10*&owner)
{
 Handle_8002B67C handle(*h);
 if(fn_801F7EB8(&handle)){
  owner=handle.resolve()->referenceB0;
  if(fn_801F7EB8(owner))return owner->resolve();
 }
 return 0;
}
int fn_800E7A74(Agent*self,int type,Event*event){
 CallbackPool*pool=&lbl_802C8ED0;int result=1;
 switch(type){
 case 0:fn_8025EF34(self,pool->second[0],-1);return 1;
 case 1:fn_8025EEB4(self,pool->second[1]);return 1;
 case 2:fn_8025EB70(self,pool->second[2]);return 1;
 case 3:if(event)return(signed char)((event->flags>>2)&1);{Event*f=fn_8025F074(self,pool->second[3]);if(f)return(signed char)((f->flags>>2)&1);}return 0;
 case 4:if(event)return(signed char)(event->flags&1);{Event*f=fn_8025F074(self,pool->second[4]);if(f)return(signed char)(f->flags&1);}return 0;
 case 5:return 1;case 6:if(event)return event->index;return -9999;
 }
 lbl_8037808C=0;lbl_80378090=0;lbl_80378094=-1;
 if(type==8||type==7)fn_8025F4F4(event,0,lbl_802AB1E8);
 if(type==11&&event->index==-1)return 1;
 fn_8025F658(event,lbl_80378090);
 switch(type>=14?type+event->index*2:type){
 case 7:fn_8025F694(event,lbl_8037808C);break;
 case 8:break;
 case 14:result=fn_8025E9FC(self,0x8A);break;
 case 15:{
  self->slot7C();Handle_80020834 parent(Handle_80020834(self->reference28));
  if(parent.get()->hasFlags(0x02000000ULL)){
   lbl_801E9D24.state->active=0;
   const Handle_801F7F10*binding=lbl_801E9D24.binding->reference->resolve()->referenceB0;
   Handle_801F7F10*resource=&binding->resolveRelated()->reference70;
   Object*target=fn_801F7EB8(resource)?resource->resolve():0;
   fn_8007D6A0((char*)target+0x318,0x2F);
   fn_80058CB8(self->target,0x238C,Handle_80020834());
   Handle_801F7F10*ref=lbl_801E9D24.binding->reference;Handle_801F7F10*owner;Object*object=ownerOf(ref,owner);
   fn_80286058(object,0x86);
  }
  break;
 }
 default:result=2;
 }
 fn_8025F620(event,lbl_80378090);return result;
}
}
