/* Related-record selector; see docs/notes/game-early-related-slot-selector.md. */
typedef unsigned long Word;
struct MemberPointer{Word a,b,c;};
struct Callback{char unknown00[0x28];unsigned short flags;short index;};
extern "C" {extern const struct SlotSelectorPool{char unknown00[0x640];MemberPointer entries[5];}lbl_802B3708;extern Word lbl_8037808C,lbl_80378090;extern int lbl_80378094;void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,Word);void fn_8025F620(Callback*,Word);}
struct Handle_801F7F10{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct NodePrefix{char unknown00[8];};
struct Node:NodePrefix{
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
virtual const Handle_801F7F10& get(int);
char unknown0C[0x2C];unsigned long long flags;char unknown40[0x18];Handle_801F7F10 record;char unknown5C[0x14];Handle_801F7F10 handle70;char unknown74[0x3C];Handle_801F7F10*child;char unknownB4[0xF8];Handle_801F7F10 actor;
};
struct NodeEntry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct NodeManager{int count,capacity;NodeEntry*entries;};
struct RecordService{char unknown00[0x1C];Handle_801F7F10*handle;};
extern "C" struct RecordContext{char unknown00[0x118];NodeManager*manager;char unknown11C[0x20];RecordService*service;}lbl_801E9D24;
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;NodeManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
struct SlotSelector:NodePrefix{
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
virtual void clear();virtual void slot88();virtual void slot8C();virtual void bind(Node*);
char unknown0C[0x1C];Handle_801F7F10 parent;char unknown2C[0x44];char unknown70;signed char enabled;unsigned char count;
};
extern "C"{Word fn_801F7EB8(const Handle_801F7F10*);signed char fn_8025E9FC(SlotSelector*,int);void fn_8025F4F4(Callback*,int,const char*);const Handle_801F7F10*fn_8025E1D4(SlotSelector*,int);extern const char lbl_8029AAF8[];}

/* Five complete original member-pointer records preceding the switch. */
extern "C" MemberPointer lbl_802B3D48[5] = {
    {0,0x98,8},
    {0,0x98,8},
    {0,0x98,8},
    {0,0x98,8},
    {0,0x98,8},
};

extern "C" int fn_8004C380(SlotSelector*self,int event,Callback*callback){
 const SlotSelectorPool*members=&lbl_802B3708;int result=1;
 switch(event){
 case 0:fn_8025EF34(self,members->entries[0],-1);return 1;
 case 1:fn_8025EEB4(self,members->entries[1]);return 1;
 case 2:fn_8025EB70(self,members->entries[2]);return 1;
 case 3:if(callback)return(signed char)((callback->flags>>2)&1);callback=fn_8025F074(self,members->entries[3]);if(callback)return(signed char)((callback->flags>>2)&1);return 0;
 case 4:if(callback)return(signed char)(callback->flags&1);callback=fn_8025F074(self,members->entries[4]);if(callback)return(signed char)(callback->flags&1);return 0;
 case 5:return 1;
 case 6:if(callback)return callback->index;return -9999;
 }
 lbl_8037808C=0;lbl_80378090=0;lbl_80378094=-1;
 if(event==8||event==7)fn_8025F4F4(callback,0,lbl_8029AAF8);
 if(event==11&&callback->index==-1)return 1;
 fn_8025F658(callback,lbl_80378090);
 int action;if(event>=14)action=event+callback->index*2;else action=event;
 switch(action){
 case 7:fn_8025F694(callback,lbl_8037808C);
 case 8:break;
 case 14:result=fn_8025E9FC(self,0x8B);break;
 case 15:{
  Node*source=resolve(self->parent);
  Node*target=resolve(source->record);
  if(self->enabled&&(source->flags&0x2000000ULL)){
   const Handle_801F7F10*handle=&resolve(*resolve(*lbl_801E9D24.service->handle)->child)->handle70;
   Node*actor;if(fn_801F7EB8(handle))actor=resolve(*handle);else actor=0;
   if(fn_801F7EB8(&actor->actor))target=resolve(resolve(actor->actor)->get(0));
  }
  for(unsigned char i=0;i<=self->count;++i){
   if(target==resolve(*fn_8025E1D4(self,i))){self->clear();self->bind(target);break;}
  }
 }break;
 default:result=2;break;
 }
 fn_8025F620(callback,lbl_80378090);return result;
}
