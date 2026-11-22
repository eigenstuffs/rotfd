typedef unsigned long u32;
struct MemberPointer{u32 a,b,c;};
struct Callback{char opaque00[0x28];unsigned short flags28;short index2A;};
extern "C" {extern const struct Pool{char opaque00[0x6BC];MemberPointer entries[5];}lbl_802B3708;extern u32 lbl_8037808C,lbl_80378090;extern int lbl_80378094;void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,u32);void fn_8025F620(Callback*,u32);}

extern "C" {signed char fn_8025E9FC(void*,int);void fn_8005EED4(void*);float fn_8025E268(void*,int);}
struct Prefix{u32 unknown00,unknown04;};
struct Object:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78(int,int);virtual void slot7C(int,int);char opaque0C[0x60-0xC];u32 field60;unsigned char byte64;};
extern "C" int fn_8004CBC0(Object*self,int event,Callback*callback){
const Pool*members=&lbl_802B3708;int result=1;
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
if(event==11&&callback->index2A==-1)return 1;
fn_8025F658(callback,0);
int action;if(event>=14)action=event+callback->index2A*2;else action=event;
switch(action){case 7:fn_8025F694(callback,lbl_8037808C);case 8:break;case 15:self->field60=(unsigned char)(int)fn_8025E268(self,0);self->byte64=(unsigned char)(int)fn_8025E268(self,1);self->slot78(0,0);self->slot7C(0,0);callback->flags28&=0xFFFB;break;default:result=2;break;}
fn_8025F620(callback,lbl_80378090);return result;
}

// Native virtual-only descriptors for the next callback family.
extern "C" MemberPointer lbl_802B3E1C[5] = {
    { 0x0, 0x78, 0x8 },
    { 0x0, 0x78, 0x8 },
    { 0x0, 0x78, 0x8 },
    { 0x0, 0x78, 0x8 },
    { 0x0, 0x78, 0x8 },
};
