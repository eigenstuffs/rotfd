typedef unsigned long u32;typedef unsigned long long u64;
struct MemberPointer{u32 a,b,c;};
struct Callback{char opaque00[0x28];unsigned short flags28;short index2A;};
extern "C"{extern const struct Pool{char opaque00[0x76C];MemberPointer entries[5];}lbl_802B3708;extern u32 lbl_8037808C,lbl_80378090;extern int lbl_80378094;void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,u32);void fn_8025F620(Callback*,u32);signed char fn_8025E9FC(void*,int);void*fn_801F7EB8(const void*);}
union Handle{u32 word;struct{signed int generation:8,index:24;}bits;};
struct Prefix{u32 unknown00,unknown04;};
struct Node:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const Handle*slot9C(int);
char opaque0C[0x38-0xC];u64 flags38;char opaque40[0x70-0x40];Handle linked70;char opaque74[0xB0-0x74];const Handle*linkedB0;char opaqueB4[0x1AC-0xB4];Handle linked1AC;
};
struct Entry{Node*object;u32 unknown04,unknown08;signed char generation;char opaque0D[3];};struct Manager{char opaque00[8];Entry*entries;};
struct GlobalLink{char opaque00[0x1C];const Handle*head1C;};
extern "C"{extern struct Context{char opaque00[0x118];Manager*manager118;char opaque11C[0x13C-0x11C];GlobalLink*link13C;}lbl_801E9D24;}
inline Node*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager118->entries[h.bits.index];return e->generation==h.bits.generation?e->object:0;}
struct ManagerBytes{char opaque00[8];char*entries;};inline Node*resolveBytes(const Handle&h){Entry*e=(Entry*)(((ManagerBytes*)lbl_801E9D24.manager118)->entries+h.bits.index*16);return e->generation==h.bits.generation?e->object:0;}
struct Object:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78(int,int);virtual void slot7C(int,int);
char opaque0C[0x28-0xC];Handle handle28;char opaque2C[0x60-0x2C];int mode60;char unknown64;signed char present65,present66;char unknown67;Node*object68,*object6C;
};
extern "C" void fn_8004D974(Object*,int);
extern "C" int fn_8004D364(Object*self,int event,Callback*callback){
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
switch(action){
case 7:fn_8025F694(callback,lbl_8037808C);case 8:break;
case 14:result=fn_8025E9FC(self,0x8B);break;
case 15:{if(resolve(self->handle28)->flags38&0x2000000ULL){self->slot78(0,0);callback->flags28&=0xFFFB;
const Handle&h=resolveBytes(*resolve(*lbl_801E9D24.link13C->head1C)->linkedB0)->linked70;
Node*target=fn_801F7EB8(&h)?resolve(h):0;
self->present66=(fn_801F7EB8(&target->linked1AC)!=0);
if(self->present66)self->object6C=resolve(*resolve(target->linked1AC)->slot9C(0));
switch(self->mode60){
case 0:if(self->object6C && self->object68==self->object6C)fn_8004D974(self,0x8B);break;
case 1:if(self->object68!=self->object6C && self->object6C && self->object68)fn_8004D974(self,0x8B);break;
case 2:if(self->present65 && !self->present66)fn_8004D974(self,0x8B);break;
case 3:if(!self->present65 && self->present66){self->object6C=resolve(*resolve(target->linked1AC)->slot9C(0));fn_8004D974(self,0x8B);}break;
}
}}break;
default:result=2;break;
}
fn_8025F620(callback,lbl_80378090);return result;
}

// Native virtual-only descriptors for the next callback family.
extern "C" MemberPointer lbl_802B3ECC = { 0x0, 0x8C, 0x8 };
