// QSnail callback registration queries and event dispatch.
// The shared six-descriptor member-function pool remains original data.
typedef unsigned long u32;
struct Prefix {u32 unknown[2];};
struct Agent:Prefix {
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
 virtual void slot9C();
 virtual void slotA0();
 virtual void slotA4();
 virtual void slotA8();
 virtual void slotAC();
 virtual void slotB0();
};
struct Event {char unknown[0x28];unsigned short flags;short index;};
typedef void (Agent::*MemberFunction)();
extern "C" {
extern MemberFunction lbl_802BFE28[6];
void fn_8025EF34(Agent*,MemberFunction,int);
void fn_8025EEB4(Agent*,MemberFunction);
void fn_8025EB70(Agent*,MemberFunction);
Event*fn_8025F074(Agent*,MemberFunction);
void fn_8025F658(Event*,int);
void fn_8025F694(Event*,int);
void fn_8025F620(Event*,int);
signed char fn_8025E9FC(Agent*,int);
extern int lbl_8037808C,lbl_80378090,lbl_80378094;
int fn_800C662C(Agent*self,int type,Event*event){
 MemberFunction*callbacks=lbl_802BFE28;
 int result=1;
 switch(type){
 case 0:fn_8025EF34(self,callbacks[1],-1);return 1;
 case 1:fn_8025EEB4(self,callbacks[2]);return 1;
 case 2:fn_8025EB70(self,callbacks[3]);return 1;
 case 3:
  if(event)return (signed char)((event->flags>>2)&1);
  {Event*found=fn_8025F074(self,callbacks[4]);if(found)return (signed char)((found->flags>>2)&1);}
  return 0;
 case 4:
  if(event)return (signed char)(event->flags&1);
  {Event*found=fn_8025F074(self,callbacks[5]);if(found)return (signed char)(found->flags&1);}
  return 0;
 case 5:return 1;
 case 6:if(event)return event->index;return -9999;
 }
 lbl_8037808C=0;lbl_80378090=0;lbl_80378094=-1;
 if(type==11&&event->index==-1)return 1;
 fn_8025F658(event,0);
 switch(type>=14?type+event->index*2:type){
 case 7:fn_8025F694(event,lbl_8037808C);break;
 case 8:break;
 case 9:result=fn_8025E9FC(self,0x51);break;
 case 14:result=1;break;
 case 15:self->slotB0();break;
 default:result=2;break;
 }
 fn_8025F620(event,lbl_80378090);
 return result;
}
}

// ABC_Agent runtime base list at 0x802BFE8C.
struct NativeAgentBaseList_802BFE8C { const void* type; unsigned long offset; unsigned long end; };
extern "C" char lbl_80375800;
extern "C" __declspec(section ".data") NativeAgentBaseList_802BFE8C lbl_802BFE8C = {
    &lbl_80375800, 0, 0
};
