typedef unsigned long u32;
struct MemberPointer{u32 a,b,c;};
struct Callback{char opaque00[0x28];unsigned short flags28;short index2A;};
extern "C" {extern const struct Pool{char opaque00[0x104];MemberPointer entries[5];}lbl_802B2BF0;extern u32 lbl_8037808C,lbl_80378090;extern int lbl_80378094;void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,u32);void fn_8025F620(Callback*,u32);}

extern "C" {signed char fn_8025E9FC(void*,int);void fn_80286058(void*,int);float fn_8025E268(void*,int);}
struct Prefix{u32 unknown00,unknown04;};
struct Object:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90(int,int);virtual void slot94();virtual void slot98();virtual void slot9C();virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void* slotB8();char opaque0C[0x70-0xC];union{u32 word;struct{signed int generation:8,index:24;}bits;}handle70;};
struct Entry{char*object;u32 unknown04,unknown08;signed char generation;char unknown0D[3];};struct Manager{char opaque00[8];Entry*entries;};extern "C"{extern struct{char opaque00[0x118];Manager*manager118;char opaque11C[0x164-0x11C];void*service164;}lbl_801E9D24;void fn_8007D6A0(void*,int);void fn_800B6C84(void*,void*,u32);extern u32 lbl_803777B0,lbl_80377640;}
inline char*resolve(const Object&self){Entry*e=&lbl_801E9D24.manager118->entries[self.handle70.bits.index];return e->generation==self.handle70.bits.generation?e->object:0;}
extern "C"{extern const char lbl_8029AA2C[];void fn_8025F4F4(Callback*,int,const char*);}
extern "C" int fn_800428F4(Object*self,int event,Callback*callback){
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
switch(action){case 7:fn_8025F694(callback,lbl_8037808C);case 8:break;case 14:result=fn_8025E9FC(self,0x67);break;case 15:fn_80286058(self,0x67);fn_8007D6A0(resolve(*self)+0x318,0);void*service=lbl_801E9D24.service164;fn_800B6C84(service,self->slotB8(),lbl_803777B0);break;default:result=2;break;}
fn_8025F620(callback,lbl_80378090);return result;
}

// Native virtual-only descriptors for the next callback family.
extern "C" MemberPointer lbl_802B2D4C[5] = {
    { 0x0, 0xCC, 0x8 },
    { 0x0, 0xCC, 0x8 },
    { 0x0, 0xCC, 0x8 },
    { 0x0, 0xCC, 0x8 },
    { 0x0, 0xCC, 0x8 },
};
