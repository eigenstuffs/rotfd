typedef unsigned long u32;
typedef unsigned long long u64;
struct MemberPointer{u32 a,b,c;};
struct Callback{char opaque00[0x28];unsigned short flags28;short index2A;};
extern "C" {
extern const struct Pool{char opaque00[0xD4];MemberPointer entries[5];}lbl_802B3708;
extern u32 lbl_8037808C,lbl_80378090;extern int lbl_80378094;
extern const char lbl_8029AAF8[];extern const float lbl_80378560;
void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);
void fn_8025F4F4(Callback*,int,const char*);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,u32);void fn_8025F620(Callback*,u32);
signed char fn_8025E9FC(void*,int);void fn_802073E8(void*,int,void*,float);
extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);
}
struct Node{char opaque00[0x38];u64 flags38;};
struct Entry{Node*object;u32 unknown04,unknown08;signed char generation;char opaque0D[3];};
struct Manager{char opaque00[8];Entry*entries;};
extern "C"{extern struct Context{char opaque00[0x118];Manager*manager118;}lbl_801E9D24;void fn_801F86C8(void*,const void*,int);}
struct Handle_801F7F10{union{u32 word;struct{signed int generation:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Handle_80020478:Handle_801F7F10{
Handle_80020478(){word=0;}~Handle_80020478(){}
static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
struct Handle_80020834:Handle_80020478{
Handle_80020834(const Handle_801F7F10&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager118,&v,1);}
Handle_80020834(const Handle_80020834&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager118,&v,1);}
~Handle_80020834(){}
static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
inline Node*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager118->entries[h.bits.index];return e->generation==h.bits.generation?e->object:0;}
struct Prefix{u32 unknown00,unknown04;};
struct Object:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90(int,int);virtual void slot94(int,int);
char opaque0C[0x28-0xC];Handle_801F7F10 handle28;
};
struct NoticePrefix{u32 unknown00;};struct Notice:NoticePrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void*slot14();};
extern "C" Notice*lbl_803776B8;
extern "C" int fn_80045030(Object*self,int event,Callback*callback){
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
if(event==8||event==7)fn_8025F4F4(callback,0,lbl_8029AAF8);
if(event==11&&callback->index2A==-1)return 1;
fn_8025F658(callback,lbl_80378090);
int action;if(event>=14)action=event+callback->index2A*2;else action=event;
switch(action){
case 7:fn_8025F694(callback,lbl_8037808C);case 8:break;
case 14:result=fn_8025E9FC(self,0x8A);break;
case 15:{Handle_80020834 h(Handle_80020834(self->handle28));
fn_802073E8(self,0x8A,resolve(h),lbl_80378560);
if(resolve(h)->flags38&0x2000000ULL)fn_802073E8(self,0x8A,lbl_803776B8->slot14(),lbl_80378560);
self->slot94(0,0);callback->flags28&=0xFFFB;
}break;
default:result=2;break;
}
fn_8025F620(callback,lbl_80378090);return result;
}

// Native virtual-only descriptors for the next callback family.
extern "C" MemberPointer lbl_802B3834[5] = {
    { 0x0, 0x94, 0x8 },
    { 0x0, 0x94, 0x8 },
    { 0x0, 0x94, 0x8 },
    { 0x0, 0x94, 0x8 },
    { 0x0, 0x94, 0x8 },
};
