/* Original record resource lifecycle; see docs/notes/game-engine-callback-dispatch-variants.md. */
typedef unsigned long u32;
struct MemberPointer{u32 a,b,c;};
struct Callback{char opaque00[0x28];unsigned short flags28;short index2A;};
extern "C" {extern const struct Pool{char opaque00[0x20C];MemberPointer entries[5];}lbl_802B2BF0;extern u32 lbl_8037808C,lbl_80378090;extern int lbl_80378094;void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,u32);void fn_8025F620(Callback*,u32);}

extern "C" {signed char fn_8025E9FC(void*,int);void fn_80286058(void*,int);void fn_8025E8F8(void*);void fn_80021724(void*);}
struct Prefix{u32 unknown00,unknown04;};
struct Object:Prefix{virtual void slot08();};
extern "C"{extern const char lbl_8029AA2C[];void fn_8025F4F4(Callback*,int,const char*);}
extern "C" int fn_800433AC(Object*self,int event,Callback*callback){
const Pool*members=&lbl_802B2BF0;int result=1;
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
if(event==8||event==7)fn_8025F4F4(callback,0,lbl_8029AA2C);
if(event==11&&callback->index2A==-1)return 1;
fn_8025F658(callback,lbl_80378090);
int action;if(event>=14)action=event+callback->index2A*2;else action=event;
switch(action){case 7:fn_8025F694(callback,lbl_8037808C);case 8:break;case 14:result=fn_8025E9FC(self,0x6A);break;case 15:fn_80286058(self,0x6A);break;default:result=2;break;}
fn_8025F620(callback,lbl_80378090);return result;
}

// Native virtual-only descriptors for the next callback family.
extern "C" MemberPointer lbl_802B2E54[5] = {
    { 0x0, 0xD8, 0x8 },
    { 0x0, 0xD8, 0x8 },
    { 0x0, 0xD8, 0x8 },
    { 0x0, 0xD8, 0x8 },
    { 0x0, 0xD8, 0x8 },
};
