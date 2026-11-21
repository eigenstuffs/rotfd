/* fn_80047B1C: callback dispatcher (sibling of 800477FC/800481AC) with the
 * costume-tent dashboard notification in action 15.
 * Strings stay external: lbl_8029AAF8..8029AB60 ("cat_default" +0x0,
 * "MSG_COSTUME_TENT_NOT_UNLOCKED" +0xC, "MSG_COSTUME_TENT_ALL" +0x2C,
 * "MSG_COSTUME_TENT_NO_CHANGE_ALLOWED" +0x44) is owned by
 * native_readable_pools_8029AAF8.cpp and viewed here as one const pool
 * struct, so the base is hoisted into r29 at entry as in the original.
 * The offset-0 string is reached as (member pointer to the +0xC string) minus
 * 0xC at the use: that keeps the original `addi r5,r29,0` (not `mr`) and,
 * unlike a direct offset-0 member pointer, schedules it before `li r4,0`.
 * The switch jump table (jumptable_802B3A70) is compiler-generated. */
typedef unsigned long u32;
typedef unsigned long Word;
struct MemberPointer{u32 a,b,c;};
struct Callback{char opaque00[0x28];unsigned short flags28;short index2A;};
extern "C" {extern const struct Pool{char opaque00[0x32C];MemberPointer entries[5];}lbl_802B3708;extern u32 lbl_8037808C,lbl_80378090;extern int lbl_80378094;void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,u32);void fn_8025F620(Callback*,u32);}
extern "C" {signed char fn_8025E9FC(void*,int);void fn_8025F4F4(Callback*,int,const char*);}
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node{char unknown00[0x38];unsigned long long flags;char unknown40[0x30];Handle_801F7F10 controlled;char unknown74[0x3C];Handle_801F7F10*related;char unknownB4[0x264];char properties[1];};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};
struct Mode{char unknown00[0x100];int state;char unknown104[0xB4];short flag1B8;short getFlag()const{return flag1B8;}};struct Message{char unknown00[0x620];Word key;};struct Scene{char unknown00[0x15058];Mode*first;char unknown1505C[4];Message*message;};
struct UI{char unknown00[0x1C];Word*key;};struct Resource{char unknown00[0x1C];Handle_801F7F10*selected;};
struct ControllerPrefix{char unknown00[0x1C];};struct Controller:ControllerPrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38(int,int,int);};
extern "C"struct Context{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x14];Resource*resource;char unknown140[0x14];Controller*controller;char unknown158[0xC];UI*ui;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F7EB8(const Handle_801F7F10*);extern Word lbl_803777C4,lbl_803777CC;void fn_800B6C84(UI*,int,Word);void fn_800C2540(Message*);void fn_8007D6A0(void*,int);}
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}Handle_80020478(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020478(){}};
struct Handle_80020834:Handle_80020478{Handle_80020834(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_80020834(const Handle_80020834&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020834(){}};
extern "C"{void fn_800B6DA8(UI*,Word,int,const Handle_80020478&);}
struct Name{Word word;Name(const char*);};extern "C"{Word fn_801F948C(Name*,const char*);void fn_800C3934(Message*,void*,Name,int,int,int,int);}inline Name::Name(const char*s){word=fn_801F948C(this,s);}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Control{char unknown00[0x1DC];signed char flag1DC;};extern "C" Control*fn_8007D074();
struct Prefix{u32 unknown00;Handle_801F7F10 self;};
struct Object:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94(int,int);char opaque0C[0x1C];Handle_801F7F10 handle28;};
struct Strings{char cat[0xC];char notUnlocked[0x20];char all[0x18];char noChange[0x24];};
extern "C" const Strings lbl_8029AAF8;
inline const char*notUnlockedName(const Strings*s){const char(Strings::*m)[0x20]=&Strings::notUnlocked;return s->*m;}
inline const char*catName(const Strings*s){return notUnlockedName(s)-sizeof(s->cat);}
extern "C" int fn_80047B1C(Object*self,int event,Callback*callback){
const Strings*const s=&lbl_8029AAF8;const Pool*members=&lbl_802B3708;int result=1;
switch(event){
case 0:fn_8025EF34(self,members->entries[0],-1);return 1;
case 1:fn_8025EEB4(self,members->entries[1]);return 1;
case 2:fn_8025EB70(self,members->entries[2]);return 1;
case 3:if(callback)return(signed char)((callback->flags28>>2)&1);callback=fn_8025F074(self,members->entries[3]);if(callback)return(signed char)((callback->flags28>>2)&1);return 0;
case 4:if(callback)return(signed char)(callback->flags28&1);callback=fn_8025F074(self,members->entries[4]);if(callback)return(signed char)(callback->flags28&1);return 0;
case 5:return 1;
case 6:if(callback)return callback->index2A;return -9999;
}
lbl_8037808C=0;lbl_80378090=0;lbl_80378094=-1;
if(event==8||event==7)fn_8025F4F4(callback,0,catName(s));
if(event==11&&callback->index2A==-1)return 1;
fn_8025F658(callback,lbl_80378090);
int action;if(event>=14)action=event+callback->index2A*2;else action=event;
switch(action){case 7:fn_8025F694(callback,lbl_8037808C);case 8:break;case 14:result=fn_8025E9FC(self,0x8A);break;
case 15:{
 self->slot7C();
 Handle_80020834 object((Handle_80020834(self->handle28)));
 if(resolve(object)->flags&0x02000000ULL){
  Control*control=fn_8007D074();control->flag1DC=1;
  if(lbl_801E9D24.scene->first->getFlag()==0){self->slot94(0,0);callback->flags28&=0xFFFB;return 0;}
  lbl_801E9D24.controller->slot38(0,0,0);
  const Handle_801F7F10&controlled=resolve(*resolve(*lbl_801E9D24.resource->selected)->related)->controlled;
  Node*node=fn_801F7EB8(&controlled)?resolve(controlled):0;
  fn_8007D6A0(node->properties,6);
  Message*message=lbl_801E9D24.scene->message;
  message->key=*lbl_801E9D24.ui->key;
  if(lbl_801E9D24.scene->first->state==3){
   const Handle_801F7F10&source=self->self;fn_800B6DA8(lbl_801E9D24.ui,lbl_803777C4,0,Handle_80020478(source));
   fn_800B6C84(lbl_801E9D24.ui,0,lbl_803777C4);
   fn_800C3934(message,self,Name(s->noChange),3,0,0,0);
  }else{
   const Handle_801F7F10&source=self->self;fn_800B6DA8(lbl_801E9D24.ui,lbl_803777CC,0,Handle_80020478(source));
   fn_800B6C84(lbl_801E9D24.ui,0,lbl_803777CC);
   fn_800C3934(message,self,Name(s->all),6,0,0,0);
  }
  fn_800C2540(message);
 }
 self->slot94(0,0);callback->flags28&=0xFFFB;
}break;
default:result=2;break;}
fn_8025F620(callback,lbl_80378090);return result;
}
