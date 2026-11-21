/* Original Handle event callback; see docs/notes/game-engine-callback-handle-events.md. */
typedef unsigned long u32;
struct MemberPointer{u32 a,b,c;};
struct Callback{char opaque00[0x28];unsigned short flags28;short index2A;};
extern "C" {
extern const struct Pool{char opaque00[0x24];MemberPointer entries[5];}lbl_802C1590;
extern u32 lbl_8037808C,lbl_80378090;extern int lbl_80378094;
void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);
void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,u32);void fn_8025F620(Callback*,u32);float fn_8025E268(void*,int);
extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);
extern struct Context{char opaque00[0x118];void*manager118;}lbl_801E9D24;
void fn_801F86C8(void*,const void*,int);void*fn_801F7EB8(const void*);
}
struct Handle_801F7F10{u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct ZeroHandle_CA254:Handle_801F7F10{ZeroHandle_CA254(){word=0;}~ZeroHandle_CA254(){}};
struct Handle_80020B90:ZeroHandle_CA254{
Handle_80020B90(){word=0;}~Handle_80020B90(){}
Handle_80020B90&operator=(const Handle_801F7F10&v){fn_801F86C8(lbl_801E9D24.manager118,this,-1);word=v.word;fn_801F86C8(lbl_801E9D24.manager118,&v,1);return*this;}
static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
extern "C" const Handle_801F7F10*fn_8025E1D4(void*,int);
struct Prefix{u32 unknown00,unknown04;};
struct Object:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C(int,int);virtual void slot80(int,int);
char opaque0C[0x60-0xC];unsigned char mode60,parameter61,count62,active63;
};
extern "C" int fn_800CA254(Object*self,int event,Callback*callback){
const Pool*members=&lbl_802C1590;int result=1;
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
switch(action){
case 7:fn_8025F694(callback,lbl_8037808C);case 8:break;
case 15:{self->mode60=(int)fn_8025E268(self,0);self->parameter61=(int)fn_8025E268(self,1);Handle_80020B90 h;
for(unsigned char i=0;i<=9;++i){h=*fn_8025E1D4(self,i);if(fn_801F7EB8(&h))++self->count62;}
if(self->mode60==1){self->slot7C(0,0);self->slot80(1,0);}else if(self->mode60==2){self->active63=self->count62;self->slot80(0,0);self->slot7C(1,0);}else{self->slot7C(0,0);self->slot80(0,0);}
callback->flags28&=0xFFFB;
}break;
default:result=2;break;
}
fn_8025F620(callback,lbl_80378090);return result;
}

// Native virtual-only descriptors for the next callback family.
extern "C" MemberPointer lbl_802C160C[5] = {
    { 0x0, 0x7C, 0x8 },
    { 0x0, 0x7C, 0x8 },
    { 0x0, 0x7C, 0x8 },
    { 0x0, 0x7C, 0x8 },
    { 0x0, 0x7C, 0x8 },
};
