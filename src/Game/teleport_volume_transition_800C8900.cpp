// TeleportVolume transition event handler (fn_800C8900).
// Notes: the record-pair read goes through reference-returning inline getters
// reached via the inline activeChoices() accessor (same idiom as matched
// menu_task_status_update_800B4628), which keeps the original indexed loads.
// The target-controller handle uses an index-first resolve (resolveIndexed);
// the relink view (resolveRelated) keeps the separate registry reload. The
// callback descriptors come from the shared pool lbl_802C1150; float
// constants are the shared labels; only the switch table is owned.
typedef unsigned long u32;typedef unsigned long long u64;
struct Object;struct Registry;struct World;struct State;
struct Globals{char unknown[0x118];Registry*registry;char unknown11C[8];World*world;char unknown128[0x3C];State*state;};
extern "C" {extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_801F7F10 {
 union{u32 value;struct{signed long generation:8;signed long index:24;}bits;};
 Handle_801F7F10();~Handle_801F7F10();
 Object*resolve()const;
 Object*resolveRelated()const;
 static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
extern "C" void fn_801F86C8(Registry*,const Handle_801F7F10*,int);
struct Handle_8001FF78:Handle_801F7F10 {
 Handle_8001FF78(){value=0;}~Handle_8001FF78(){}
};
struct Handle_80020478:Handle_801F7F10 {
 Handle_80020478(){value=0;}~Handle_80020478(){}
};
struct Handle_80020834:Handle_80020478 {
 Handle_80020834(){value=0;}~Handle_80020834(){}
};
struct Handle_80020B90:Handle_8001FF78 {
 Handle_80020B90(const Handle_801F7F10&other){value=other.value;fn_801F86C8(lbl_801E9D24.registry,&other,1);}
 ~Handle_80020B90(){}
};
struct Handle_8003E120:Handle_80020834 {
 Handle_8003E120();Handle_8003E120(const Handle_8003E120&other){value=other.value;fn_801F86C8(lbl_801E9D24.registry,&other,1);}
 ~Handle_8003E120(){}
};
struct Vec3{float x,y,z;Vec3&operator=(const Vec3&o){x=o.x;y=o.y;z=o.z;return *this;}};
struct Quat{float w,x,y,z;Quat&operator=(const Quat&o){w=o.w;x=o.x;y=o.y;z=o.z;return *this;}};
struct Prefix{u32 unknown[2];};
struct Object:Prefix {
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
 virtual void slot74(float,int);
 virtual void slot78();
 virtual void slot7C();
 virtual void slot80();
 virtual void slot84();
 virtual void slot88();
 virtual void slot8C();
 virtual void slot90();
 virtual void slot94();
 virtual void slot98();
 virtual void slot9C();
 virtual void slotA0();
 virtual void slotA4();
 virtual void slotA8();
 virtual void slotAC();
 virtual void slotB0();
 virtual void slotB4();
 virtual void slotB8();
 virtual void slotBC();
 virtual void slotC0(const Vec3*,const Quat*,int);
 char unknown0C[0x38-0xC];u64 flags;
 char unknown40[0x20];Handle_801F7F10 reference60;char unknown64[0x18];Vec3 position7C;char unknown88[0xC];Quat rotation94;
 char unknownA4[0x130-0xA4];Handle_801F7F10 reference130;char unknown134[0x1AC-0x134];Handle_801F7F10 reference1AC;
 char unknown1B0[0x2D0-0x1B0];Vec3 position2D0;Quat rotation2DC;char unknown2EC[4];u32 field2F0;char unknown2F4[0x318-0x2F4];char state318[0x458-0x318];float scale458;
 bool hasFlags(u64 mask){return (flags&mask)!=0;}
};
struct Entry{Object*object;u32 unknown[2];signed char generation;char padding[3];signed char getTag()const{return generation;}};
struct Registry{int size,capacity;Entry*entries;};
struct RelatedRegistry{int size,capacity;Entry*entries;};
inline Object*Handle_801F7F10::resolve()const{Entry*entry=&lbl_801E9D24.registry->entries[bits.index];return entry->generation==bits.generation?entry->object:0;}
inline Object*Handle_801F7F10::resolveRelated()const{Entry*entry=&((RelatedRegistry*)lbl_801E9D24.registry)->entries[bits.index];return entry->generation==bits.generation?entry->object:0;}
inline Object*resolveIndexed(const Handle_801F7F10&h){int index=h.bits.index;Registry*m=lbl_801E9D24.registry;int tag=m->entries[index].getTag();return tag==h.bits.generation?m->entries[index].object:0;}
struct World{char unknown[0x15058];Object*active;};
struct State{char unknown[0x2D];char active;};
struct Choice{u32 unknown[2];u32 first,second;};
struct TargetChoices{char unknown[0xEC];Choice*data;Choice&at(int i){return data[i];}u32 getSecond(int i){return at(i).second;}u32 getFirst(int i){return at(i).first;}};
inline TargetChoices*activeChoices(){return (TargetChoices*)lbl_801E9D24.world->active;}
struct Agent:Prefix{char unknown08[0x70-8];Handle_801F7F10 reference70;char unknown74[0x10];Vec3 position84,position90;Quat rotation9C;signed char fieldAC,fieldAD;char paddingAE[2];u32 fieldB0,fieldB4;Object*target;Object*resource;};
struct Event{char unknown[0x28];unsigned short flags;short index;};
typedef void (Object::*MemberFunction)();
struct CallbackPool{MemberFunction first[8];char firstJumpTable[28];MemberFunction second[5];char secondJumpTable[28];MemberFunction third[5];};
extern "C" {
extern CallbackPool lbl_802C1150;
extern int lbl_8037808C,lbl_80378090,lbl_80378094;
extern const char lbl_802A27A8[];
extern const float lbl_8037962C,lbl_80379630;
void fn_8025EF34(Agent*,MemberFunction,int);void fn_8025EEB4(Agent*,MemberFunction);void fn_8025EB70(Agent*,MemberFunction);Event*fn_8025F074(Agent*,MemberFunction);
void fn_8025F4F4(Event*,int,const char*);void fn_8025F658(Event*,int);void fn_8025F694(Event*,int);void fn_8025F620(Event*,int);signed char fn_8025E9FC(Agent*,int);
Handle_8003E120 fn_800BCF58(World*,const Handle_801F7F10*);
void fn_80030E9C(Object*,int,int);void fn_80031654(Object*,u32,u32);
void fn_8007D6A0(void*,int);Handle_801F7F10*fn_8025E1D4(Agent*,int);Object*fn_801F7EB8(const Handle_801F7F10*);
void fn_800A64E0(Object*,int);void*fn_8007D074();void fn_80078D6C(void*);
int fn_800C8900(Agent*self,int type,Event*event){
 CallbackPool*pool=&lbl_802C1150;int result=1;
 switch(type){
 case 0:fn_8025EF34(self,pool->third[0],-1);return 1;
 case 1:fn_8025EEB4(self,pool->third[1]);return 1;
 case 2:fn_8025EB70(self,pool->third[2]);return 1;
 case 3:if(event)return(signed char)((event->flags>>2)&1);{Event*f=fn_8025F074(self,pool->third[3]);if(f)return(signed char)((f->flags>>2)&1);}return 0;
 case 4:if(event)return(signed char)(event->flags&1);{Event*f=fn_8025F074(self,pool->third[4]);if(f)return(signed char)(f->flags&1);}return 0;
 case 5:return 1;case 6:if(event)return event->index;return -9999;
 }
 lbl_8037808C=0;lbl_80378090=0;lbl_80378094=-1;
 if(type==8||type==7)fn_8025F4F4(event,0,lbl_802A27A8);
 if(type==11&&event->index==-1)return 1;
 fn_8025F658(event,lbl_80378090);
 switch(type>=14?type+event->index*2:type){
 case 7:fn_8025F694(event,lbl_8037808C);break;
 case 8:break;
 case 14:result=fn_8025E9FC(self,0x8C);break;
 case 15:{
  lbl_801E9D24.state->active=1;self->resource->scale458=lbl_80379630;
  if(self->fieldAC){
   Handle_8003E120 handle(fn_800BCF58(lbl_801E9D24.world,&self->reference70));
   fn_80030E9C(handle.resolve(),0,0);
   Object*active=lbl_801E9D24.world->active;
   u32 first=activeChoices()->getSecond(self->fieldB0);u32 second=activeChoices()->getFirst(self->fieldB0);
   active->field2F0=self->fieldB4;
   fn_80031654(handle.resolve(),first,second);
  }else if(self->fieldAD){
   fn_8007D6A0(self->resource->state318,0);
   Handle_80020B90 handle(*fn_8025E1D4(self,2));
   if(fn_801F7EB8(&handle)){
    Object*object=handle.resolve()->reference130.resolveRelated();
    if(object&&object->hasFlags(0x40000000ULL)){
     self->position84=object->position7C;self->rotation9C=object->rotation94;
     {Object*target=self->target;target->position2D0=self->position84;target->rotation2DC=self->rotation9C;}
    }
   }else{self->position84=self->target->position2D0;self->rotation9C=self->target->rotation2DC;}
  }else{
   {Object*target=self->target;target->position2D0=self->position84;target->rotation2DC=self->rotation9C;}
   fn_800A64E0(resolveIndexed(self->target->reference60),0);
   if(fn_801F7EB8(&self->resource->reference1AC))fn_8007D6A0(self->resource->state318,0x18);
   else fn_8007D6A0(self->resource->state318,0);
   Handle_80020B90 handle(*fn_8025E1D4(self,2));
   if(fn_801F7EB8(&handle)){
    Object*object=handle.resolve()->reference130.resolveRelated();
    if(object){self->position84=object->position7C;self->rotation9C=object->rotation94;
     {Object*target=self->target;target->position2D0=self->position84;target->rotation2DC=self->rotation9C;}}
   }
  }
  self->resource->slotC0(&self->position84,&self->rotation9C,0);
  self->resource->slot74(lbl_8037962C,0);
  if(!self->fieldAC)fn_80078D6C(fn_8007D074());
  event->flags&=0xFFFB;break;
 }
 default:result=2;break;
 }
 fn_8025F620(event,lbl_80378090);return result;
}
}
