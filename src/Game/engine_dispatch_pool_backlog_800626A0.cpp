typedef unsigned long u32;
struct MemberPointer{u32 a,b,c;};
struct Callback{char opaque00[0x28];unsigned short flags28;short index2A;};
extern "C" {extern const struct Pool{char opaque00[0x70];MemberPointer entries[5];}lbl_802B6028;extern u32 lbl_8037808C,lbl_80378090;extern int lbl_80378094;void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,u32);void fn_8025F620(Callback*,u32);}

extern "C" {signed char fn_8025E9FC(void*,int);void fn_80286058(void*,int);void fn_8025E8F8(void*);void fn_80021724(void*);}
struct Prefix{u32 unknown00,unknown04;};
struct Object:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();char opaque0C[0x38-0xC];unsigned long long flags38;};
extern "C" MemberPointer lbl_802B6098[5] = {
    {0,0xDC,8},
    {0,0xDC,8},
    {0,0xDC,8},
    {0,0xDC,8},
    {0,0xDC,8},
};

extern "C" int slotDC__11CLevelAgentFv(Object*self,int event,Callback*callback){
const Pool*members=&lbl_802B6028;int result=1;
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
switch(action){case 7:fn_8025F694(callback,lbl_8037808C);case 8:break;case 14:result=0;if(fn_8025E9FC(self,0x51)||fn_8025E9FC(self,0x52))result=1;result=(unsigned char)result;break;case 15:self->flags38|=0x20000ULL;self->slot34();fn_8025E8F8(self);break;default:result=2;break;}
fn_8025F620(callback,lbl_80378090);return result;
}
