typedef unsigned long u32;
struct MemberPointer{u32 a,b,c;};
struct Callback{char opaque00[0x28];unsigned short flags28;short index2A;};
extern "C" {extern const MemberPointer lbl_802C8ED0[7];extern u32 lbl_8037808C,lbl_80378090;extern int lbl_80378094;void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,u32);void fn_8025F620(Callback*,u32);void fn_800E8FF4(void*);}

struct ObjectPrefix{u32 unknown00,unknown04;};
struct Object:ObjectPrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94(int,int);};
extern "C" {extern const char lbl_802AB1E8[12];void fn_8025F4F4(Callback*,int,const char*);signed char fn_8025E9FC(void*,int);}
extern "C" int fn_800E7784(Object*self,int event,Callback*callback){
const MemberPointer*members=lbl_802C8ED0;int result=1;
switch(event){
case 0:fn_8025EF34(self,members[2],-1);return 1;
case 1:fn_8025EEB4(self,members[3]);return 1;
case 2:fn_8025EB70(self,members[4]);return 1;
case 3:if(callback)return(signed char)((callback->flags28>>2)&1);callback=fn_8025F074(self,members[5]);if(callback)return(signed char)((callback->flags28>>2)&1);return 0;
case 4:if(callback)return(signed char)(callback->flags28&1);callback=fn_8025F074(self,members[6]);if(callback)return(signed char)(callback->flags28&1);return 0;
case 5:return 1;
case 6:if(callback)return callback->index2A;return -9999;
}
lbl_8037808C=0;lbl_80378090=0;lbl_80378094=-1;
if(event==8||event==7)fn_8025F4F4(callback,0,lbl_802AB1E8);
if(event==11&&callback->index2A==-1)return 1;
fn_8025F658(callback,lbl_80378090);
int action;if(event>=14)action=event+callback->index2A*2;else action=event;
switch(action){case 7:fn_8025F694(callback,lbl_8037808C);case 8:break;case 14:result=0;if(fn_8025E9FC(self,0x51)||fn_8025E9FC(self,0x8F))result=1;result=(unsigned char)result;break;case 15:self->slot94(0,0);self->slot90();callback->flags28&=0xFFFB;break;default:result=2;break;}
fn_8025F620(callback,lbl_80378090);return result;
}
