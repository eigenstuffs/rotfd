/* Scene mode request, UI notification and controlled-actor transition. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ActorIndex{int value;ActorIndex(int v):value(v){}operator const int&()const{return value;}};
struct Node{char unknown00[0x70];Handle_801F7F10 controlled;char unknown74[0x3C];Handle_801F7F10*related;char unknownB4[0xF8];Handle_801F7F10 attached;char unknown1B0[0x168];char properties[1];};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};struct Manager{int count,capacity;EntryArray entries;};
struct Mode{char unknown00[0x60];Handle_801F7F10 resource;char unknown64[0x9C];int state;char unknown104[0xB6];short firstFlag,secondFlag;short getFirst()const{return firstFlag;}short getSecond()const{return secondFlag;}};
struct Message{char unknown00[0x620];Word key;};struct Scene{char unknown00[0x15058];Mode*first;char unknown1505C[4];Message*message;};struct Resource{char unknown00[0x1C];Handle_801F7F10*selected;};struct UI;
struct ControllerPrefix{char unknown00[0x1C];};struct Controller:ControllerPrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38(int,int,int);};
struct ServicePrefix{char unknown00[0x7C];};struct Service:ServicePrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();};
extern "C"struct Context{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x14];Resource*resource;char unknown140[0x14];Controller*controller;Service*service;char unknown15C[8];UI*ui;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F7EB8(const Handle_801F7F10*);extern Word lbl_803777C4,lbl_803777CC;void fn_800B6C84(UI*,int,Word);void fn_800C2700(Message*);void fn_8007D6A0(void*,int);void fn_800A7798(Node*);void fn_80057100(Mode*,int);void fn_80208C24();void fn_802603A0(Scene*,int,Mode*,float);void fn_800A8520(Node*,signed char,int);}
struct Handle_80020478:Handle_801F7F10{Handle_80020478(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C"{void fn_800B6F70(UI*,Word,int,const Handle_80020478&);void fn_800B6DA8(UI*,Word,int,const Handle_80020478&);}
struct Name{Word word;Name(const char*);Name(const Name&n){word=n.word;}};extern "C"{Word fn_801F948C(Name*,const char*);extern const char lbl_8029AB04[];void fn_800C3934(Message*,Word,Name,void*,int,const char*,const char*);}inline Name::Name(const char*s){word=fn_801F948C(this,s);}
inline Node*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const ActorIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
inline const Handle_801F7F10&controlled(){return resolve(*resolve(*lbl_801E9D24.resource->selected)->related)->controlled;}
inline Node*resolveValid(const Handle_801F7F10&h){return fn_801F7EB8(&h)?resolve(h):0;}
struct Owner{Word unknown00;Handle_801F7F10 self;};
extern "C"void fn_80046D60(Owner*self,int requested){
 int previous;Mode*mode=lbl_801E9D24.scene->first;
 signed char second=false,first=false;if(mode->getFirst())first=true;if(mode->getSecond())second=true;
 switch(requested){case 0:case 1:break;
 case 2:if(!first){
  const Handle_801F7F10&source=self->self;fn_800B6F70(lbl_801E9D24.ui,lbl_803777CC,0,Handle_80020478(source));
  const Handle_801F7F10&original=self->self;fn_800B6DA8(lbl_801E9D24.ui,lbl_803777C4,0,Handle_80020478(original));
  fn_800B6C84(lbl_801E9D24.ui,0,lbl_803777C4);
  Message*message=lbl_801E9D24.scene->message;fn_800C3934(message,reinterpret_cast<Word>(self),Name(Name(lbl_8029AB04)),reinterpret_cast<void*>(3),0,0,0);return;
 }break;
 case 5:if(!second){
  const Handle_801F7F10&source=self->self;fn_800B6F70(lbl_801E9D24.ui,lbl_803777CC,0,Handle_80020478(source));
  const Handle_801F7F10&original=self->self;fn_800B6DA8(lbl_801E9D24.ui,lbl_803777C4,0,Handle_80020478(original));
  fn_800B6C84(lbl_801E9D24.ui,0,lbl_803777C4);
  Message*message=lbl_801E9D24.scene->message;fn_800C3934(message,reinterpret_cast<Word>(self),Name(Name(lbl_8029AB04)),reinterpret_cast<void*>(3),0,0,0);return;
 }break;
 }
 previous=mode->state;
 lbl_801E9D24.controller->slot38(0,0,0);
 const Handle_801F7F10&source=self->self;fn_800B6F70(lbl_801E9D24.ui,lbl_803777CC,0,Handle_80020478(source));
 fn_800B6C84(lbl_801E9D24.ui,0,lbl_801E9D24.scene->message->key);
 fn_800A7798(resolve(mode->resource));
 fn_80057100(lbl_801E9D24.scene->first,-1);
 lbl_801E9D24.service->slot68();fn_80208C24();
 fn_800C2700(lbl_801E9D24.scene->message);
 if(requested==previous){
  if(!fn_801F7EB8(&resolveValid(controlled())->attached))fn_8007D6A0(resolveValid(controlled())->properties,0);
  else fn_8007D6A0(resolveValid(controlled())->properties,0x18);
 }else{
  fn_802603A0(lbl_801E9D24.scene,0x57,mode,float(requested));
  fn_800A8520(resolve(mode->resource),0,0);
 }
}
