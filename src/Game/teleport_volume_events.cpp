// TeleportVolume callback queries and state-change event dispatch.
// Callback queries use the native virtual-call descriptor storage view.
#include "Game/teleport_virtual_callback_records.h"
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
 virtual void slot94(int,int);
 virtual void slot98();
 virtual void slot9C();
 virtual void slotA0();
 virtual void slotA4();
 virtual void slotA8();
 virtual void slotAC();
 virtual void slotB0();
};
struct Event {char unknown[0x28];unsigned short flags;short index;};
typedef TeleportVirtualCallback VirtualCallback;
extern "C" {
void fn_8025EF34(Agent*,VirtualCallback,int);
void fn_8025EEB4(Agent*,VirtualCallback);
void fn_8025EB70(Agent*,VirtualCallback);
Event*fn_8025F074(Agent*,VirtualCallback);
void fn_8025F658(Event*,int);
void fn_8025F4F4(Event*,int,const char*);
extern const char lbl_802A27A8[];
void fn_8025F694(Event*,int);
void fn_8025F620(Event*,int);
signed char fn_8025E9FC(Agent*,int);
extern int lbl_8037808C,lbl_80378090,lbl_80378094;
int fn_800C7D70(Agent*self,int type,Event*event){
 VirtualCallback*callbacks=lbl_802C1150;
 int result=1;
 switch(type){
 case 0:fn_8025EF34(self,callbacks[3],-1);return 1;
 case 1:fn_8025EEB4(self,callbacks[4]);return 1;
 case 2:fn_8025EB70(self,callbacks[5]);return 1;
 case 3:
  if(event)return (signed char)((event->flags>>2)&1);
  {Event*found=fn_8025F074(self,callbacks[6]);if(found)return (signed char)((found->flags>>2)&1);}
  return 0;
 case 4:
  if(event)return (signed char)(event->flags&1);
  {Event*found=fn_8025F074(self,callbacks[7]);if(found)return (signed char)(found->flags&1);}
  return 0;
 case 5:return 1;
 case 6:if(event)return event->index;return -9999;
 }
 lbl_8037808C=0;lbl_80378090=0;lbl_80378094=-1;
 if(type==8||type==7)fn_8025F4F4(event,0,lbl_802A27A8);
 if(type==11&&event->index==-1)return 1;
 fn_8025F658(event,lbl_80378090);
 switch(type>=14?type+event->index*2:type){
 case 7:fn_8025F694(event,lbl_8037808C);break;
 case 8:break;
 case 14:result=(fn_8025E9FC(self,0x51)||fn_8025E9FC(self,0x8F));break;
 case 15:self->slot94(0,0);self->slot90();event->flags&=0xFFFB;break;
 default:result=2;break;
 }
 fn_8025F620(event,lbl_80378090);
 return result;
}
}

// Next teleport callback query family: five native virtual descriptors.
extern "C" TeleportVirtualCallback lbl_802C11CC[5] = {
    {0,0x94,8}, {0,0x94,8}, {0,0x94,8}, {0,0x94,8}, {0,0x94,8}
};
