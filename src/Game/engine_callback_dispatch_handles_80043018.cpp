/* Original cyclic record selection callback; see docs/notes/game-engine-callback-dispatch-handles.md. */
typedef unsigned long u32;
struct MemberPointer{u32 a,b,c;};
struct Callback{char opaque00[0x28];unsigned short flags28;short index2A;};
extern "C" {
extern const struct Pool{char opaque00[0x15C];MemberPointer entries[5];char opaque198[0x1B4-0x198];MemberPointer nextEntries[5];}lbl_802B2BF0;
extern u32 lbl_8037808C,lbl_80378090;extern int lbl_80378094;
extern const char lbl_8029AA2C[];extern int lbl_80377640;
void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);
void fn_8025F4F4(Callback*,int,const char*);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,u32);void fn_8025F620(Callback*,u32);
signed char fn_8025E9FC(void*,int);void fn_80286058(void*,int);
extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);
extern struct Context{char opaque00[0x118];void*manager118;char opaque11C[0x144-0x11C];void*records144;}lbl_801E9D24;
void fn_801F86C8(void*,const void*,int);void*fn_801F7EB8(const void*);void fn_8025795C(void*,int,int);
}
struct Handle_801F7F10{u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct Handle_8001FF78:Handle_801F7F10{
Handle_8001FF78(){word=0;}~Handle_8001FF78(){}
static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
struct Handle_80042FA4:Handle_8001FF78{
Handle_80042FA4(){word=0;}
Handle_80042FA4(const Handle_801F7F10&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager118,&v,1);}
~Handle_80042FA4(){}
Handle_80042FA4&operator=(const Handle_80042FA4&v){fn_801F86C8(lbl_801E9D24.manager118,this,-1);word=v.word;fn_801F86C8(lbl_801E9D24.manager118,&v,1);return*this;}
static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
extern "C" Handle_801F7F10 fn_801F5C04(void*,int,int);
struct Object{char opaque00[0x68];int record68;};
extern "C" int fn_80043018(Object*self,int event,Callback*callback){
const Pool*members=&lbl_802B2BF0;int result=1;
switch(event){
case 0:fn_8025EF34(self,members->nextEntries[0],-1);return 1;
case 1:fn_8025EEB4(self,members->nextEntries[1]);return 1;
case 2:fn_8025EB70(self,members->nextEntries[2]);return 1;
case 3:if(callback)return(signed char)((callback->flags28>>2)&1);callback=fn_8025F074(self,members->nextEntries[3]);if(callback)return(signed char)((callback->flags28>>2)&1);return 0;
case 4:if(callback)return(signed char)(callback->flags28&1);callback=fn_8025F074(self,members->nextEntries[4]);if(callback)return(signed char)(callback->flags28&1);return 0;
case 5:return 1;
case 6:if(callback)return callback->index2A;return -9999;
}
lbl_8037808C=0;lbl_80378090=0;lbl_80378094=-1;
if(event==8||event==7)fn_8025F4F4(callback,0,lbl_8029AA2C);
if(event==11&&callback->index2A==-1)return 1;
fn_8025F658(callback,lbl_80378090);
int action;if(event>=14)action=event+callback->index2A*2;else action=event;
switch(action){
case 7:fn_8025F694(callback,lbl_8037808C);case 8:break;
case 14:result=fn_8025E9FC(self,0x69);break;
case 15:{fn_80286058(self,0x69);if(++lbl_80377640>=0xBC)lbl_80377640=0;
Handle_80042FA4 h;
if(self->record68>=0){h=Handle_80042FA4(fn_801F5C04(lbl_801E9D24.records144,self->record68,lbl_80377640));if(fn_801F7EB8(&h))fn_8025795C(self,lbl_80377640,0);}
}break;
default:result=2;break;
}
fn_8025F620(callback,lbl_80378090);return result;
}

// Native virtual-only descriptors for the next callback family.
extern "C" MemberPointer lbl_802B2DFC[5] = {
    { 0x0, 0xD4, 0x8 },
    { 0x0, 0xD4, 0x8 },
    { 0x0, 0xD4, 0x8 },
    { 0x0, 0xD4, 0x8 },
    { 0x0, 0xD4, 0x8 },
};
