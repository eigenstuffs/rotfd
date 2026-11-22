typedef unsigned long u32;
struct MemberPointer{u32 a,b,c;};
struct Callback{char opaque00[0x28];unsigned short flags28;short index2A;};
extern "C" {extern const struct Pool{char opaque00[0xD4];MemberPointer entries[5];}lbl_802C1590;extern u32 lbl_8037808C,lbl_80378090;extern int lbl_80378094;void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,u32);void fn_8025F620(Callback*,u32);}

union Handle{u32 word;struct{signed int generation:8,index:24;}bits;};
struct Node{char opaque00[0x58];Handle linked58;};
struct Entry{Node*object;u32 unknown04,unknown08;signed char generation;char unknown0D[3];};
struct Manager{char opaque00[8];Entry*entries;};
extern "C"{extern struct Context{char opaque00[0x118];Manager*manager118;}lbl_801E9D24;signed char fn_8025E9FC(void*,int);const Handle*fn_8025E1D4(void*,int);}
inline Node*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager118->entries[h.bits.index];return e->generation==h.bits.generation?e->object:0;}
struct Prefix{u32 unknown00,unknown04;};
struct Object:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C(int,int);virtual void slot80(int,int);char opaque0C[0x28-0xC];Handle handle28;char opaque2C[0x60-0x2C];unsigned char mode60,unknown61,count62;signed char active63;};
struct ManagerBytes{char opaque00[8];char*entries;};inline Node*resolveBytes(const Handle&h){Entry*e=(Entry*)(((ManagerBytes*)lbl_801E9D24.manager118)->entries+h.bits.index*16);return e->generation==h.bits.generation?e->object:0;}
extern "C" int fn_800CAA20(Object*self,int event,Callback*callback){
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
switch(action){case 7:fn_8025F694(callback,lbl_8037808C);case 8:break;case 14:result=fn_8025E9FC(self,0x8B);break;case 15:{Node*target=resolveBytes(resolve(self->handle28)->linked58);for(unsigned char i=0;i<=self->count62;++i){if(target==resolve(*fn_8025E1D4(self,i))){--self->active63;if(self->mode60==2)self->slot7C(0,0);break;}}}break;default:result=2;break;}
fn_8025F620(callback,lbl_80378090);return result;
}

// ABC_Agent runtime base list at 0x802C16BC.
struct NativeAgentBaseList_802C16BC { const void* type; unsigned long offset; unsigned long end; };
extern "C" char lbl_803758B8;
extern "C" __declspec(section ".data") NativeAgentBaseList_802C16BC lbl_802C16BC = {
    &lbl_803758B8, 0, 0
};
