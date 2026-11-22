/* TeleportVolume translation-unit tail: runtime base lists, the native
 * TeleportVolume method table and pooled member-pointer constants (.data
 * 0x802C1288..0x802C1418, formerly native_rtti_base_lists_802C1288.cpp) with
 * the callback dispatcher fn_800C96E0, whose switch table the compiler emits
 * after them (0x802C13FC is 4 mod 8, so it cannot be owned separately). The
 * member-pointer pool is defined in one namespace and viewed through an extern
 * declaration in another, so the dispatcher reads it as unknown external data.
 */
#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802C1288 = {
    {
        { &lbl_80375858, 0 }, // BaseObject_Z
        { &lbl_80375860, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for VolumeAgent_Z.
NativeRuntimeBaseList<3> lbl_802C129C = {
    {
        { &lbl_80375858, 0 }, // BaseObject_Z
        { &lbl_80375860, 0 }, // ABC_Agent
        { &lbl_80375868, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for Volume_ScriptAndDebug.
NativeRuntimeBaseList<4> lbl_802C12B8 = {
    {
        { &lbl_80375858, 0 }, // BaseObject_Z
        { &lbl_80375860, 0 }, // ABC_Agent
        { &lbl_80375868, 0 }, // Agent_Z
        { &lbl_80375870, 0 }, // VolumeAgent_Z
    }, 0
};

// Base hierarchy for Volume_Teleport.
NativeRuntimeBaseList<5> lbl_802C12DC = {
    {
        { &lbl_80375858, 0 }, // BaseObject_Z
        { &lbl_80375860, 0 }, // ABC_Agent
        { &lbl_80375868, 0 }, // Agent_Z
        { &lbl_80375870, 0 }, // VolumeAgent_Z
        { &lbl_80375878, 0 }, // Volume_ScriptAndDebug
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__14TeleportVolumeFv();
void slot48__7Agent_ZFv();
void slot4C__7Agent_ZFv();
void slot50__7Agent_ZFv();
void slot70__7Agent_ZFv();
void slot54__7Agent_ZFv();
void slot58__7Agent_ZFv();
void slot5C__7Agent_ZFv();
void slot60__7Agent_ZFv();
void fn_8002DAD8();
void slot64__7Agent_ZFv();
void slot68__7Agent_ZFv();
void fn_80044448();
void fn_80044494();
void fn_80044578();
void fn_80044618();
void fn_800446B8();
void fn_800447A8();
void fn_80044904();
void fn_80044908();
void fn_800C7924();
void fn_800C796C();
void fn_800C79B4();
void fn_800C7A24();
void fn_800C7D70();
void fn_800C8060();
void fn_800C8900();
void fn_800C9130();
void fn_800C9138();
void fn_800C9140();
void fn_800C91A4();
void slot6C__7Agent_ZFv();
void fn_8025E11C();
void fn_8025E2FC();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot1C__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const __vt__14TeleportVolume[40] __attribute__((aligned(4))) = {
    &lbl_80375880,
    0,
    (const void*)__dt__14TeleportVolumeFv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800C7924,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)fn_800C9130,
    (const void*)fn_800C9138,
    (const void*)fn_800C9140,
    (const void*)fn_800C91A4,
    (const void*)fn_80044448,
    (const void*)fn_80044494,
    (const void*)fn_800C796C,
    (const void*)fn_8025E2FC,
    (const void*)fn_800C79B4,
    (const void*)fn_8002DAD8,
    (const void*)slot48__7Agent_ZFv,
    (const void*)slot4C__7Agent_ZFv,
    (const void*)slot50__7Agent_ZFv,
    (const void*)slot54__7Agent_ZFv,
    (const void*)slot58__7Agent_ZFv,
    (const void*)slot5C__7Agent_ZFv,
    (const void*)slot60__7Agent_ZFv,
    (const void*)slot64__7Agent_ZFv,
    (const void*)slot68__7Agent_ZFv,
    (const void*)slot6C__7Agent_ZFv,
    (const void*)slot70__7Agent_ZFv,
    (const void*)fn_8025E11C,
    (const void*)fn_80044578,
    (const void*)fn_80044904,
    (const void*)fn_800446B8,
    (const void*)fn_800447A8,
    (const void*)fn_80044618,
    (const void*)fn_80044908,
    (const void*)fn_800C7A24,
    (const void*)fn_800C8060,
    (const void*)fn_800C7D70,
    (const void*)fn_800C8900,
};

namespace pooled_member_pointers {
extern "C" __declspec(section ".data") const void* const lbl_802C13A8[3] __attribute__((aligned(4))) = {
    0,
    (const void*)0x0000008C,
    (const void*)0x00000008,
};
}


namespace pooled_member_pointers {
extern "C" __declspec(section ".data") const void* const lbl_802C13B4[18] __attribute__((aligned(4))) = {
    0,
    (const void*)0x00000090,
    (const void*)0x00000008,
    0,
    (const void*)0x00000090,
    (const void*)0x00000008,
    0,
    (const void*)0x00000090,
    (const void*)0x00000008,
    0,
    (const void*)0x00000090,
    (const void*)0x00000008,
    0,
    (const void*)0x00000090,
    (const void*)0x00000008,
    0,
    (const void*)0x00000090,
    (const void*)0x00000008,
};
}



typedef unsigned long u32;typedef unsigned long long u64;
struct MemberPointer{u32 a,b,c;};
struct Callback{char opaque00[0x28];unsigned short flags28;short index2A;};
extern "C"{}
namespace slot_exchange_view {
extern "C" const struct Pool{char opaque00[0x18];MemberPointer entries[5];}lbl_802C13A8;
}
using slot_exchange_view::Pool;
using slot_exchange_view::lbl_802C13A8;
extern "C" {
extern u32 lbl_8037808C,lbl_80378090;extern int lbl_80378094;
extern const char lbl_802A2808[];extern const float lbl_80379644;
void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);
void fn_8025F4F4(Callback*,int,const char*);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,u32);void fn_8025F620(Callback*,u32);
signed char fn_8025E9FC(void*,int);void*fn_801F7EB8(const void*);void fn_802073E8(void*,int,void*,float);void fn_802073BC(void*,int,void*,float,float);}
union Handle{u32 word;struct{signed int generation:8,index:24;}bits;};
struct Node{char opaque00[0x24];Handle handle24;char opaque28[0x70-0x28];Handle linked70;char opaque74[0x84-0x74];int count84;char opaque88[0xB0-0x88];const Handle*linkedB0;};
struct Entry{Node*object;u32 unknown04,unknown08;signed char generation;char opaque0D[3];};struct Manager{char opaque00[8];Entry*entries;};
struct GlobalLink{char opaque00[0x1C];const Handle*head1C;};
extern "C"{extern struct Context{char opaque00[0x118];Manager*manager118;char opaque11C[0x13C-0x11C];GlobalLink*link13C;}lbl_801E9D24;}
inline Node*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager118->entries[h.bits.index];return e->generation==h.bits.generation?e->object:0;}
struct ManagerBytes{char opaque00[8];char*entries;};inline Node*resolveBytes(const Handle&h){Entry*e=(Entry*)(((ManagerBytes*)lbl_801E9D24.manager118)->entries+h.bits.index*16);return e->generation==h.bits.generation?e->object:0;}
struct Object{char opaque00[0x68];signed char flag68;char opaque69[0x74-0x69];float value74;char opaque78;char mode79;};
inline Node*resolveChecked(const Handle&h){return fn_801F7EB8(&h)?resolve(h):0;}
extern "C" int fn_800C96E0(Object*self,int event,Callback*callback){
const Pool*members=&lbl_802C13A8;int result=1;
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
if(event==8||event==7)fn_8025F4F4(callback,0,lbl_802A2808);
if(event==11&&callback->index2A==-1)return 1;
fn_8025F658(callback,lbl_80378090);
int action;if(event>=14)action=event+callback->index2A*2;else action=event;
switch(action){
case 7:fn_8025F694(callback,lbl_8037808C);case 8:break;
case 14:result=fn_8025E9FC(self,0x8F)&&self->flag68;break;
case 15:if(self->mode79==1){
Node*other=resolve(resolveChecked(resolveBytes(*resolve(*lbl_801E9D24.link13C->head1C)->linkedB0)->linked70)->handle24);
if(other->count84<=0){fn_802073E8(self,0x8B,self,lbl_80379644);return 1;}
fn_802073BC(self,0x8F,self,self->value74,lbl_80379644);
fn_802073E8(self,0x87,other,lbl_80379644);
}break;

default:result=2;break;
}
fn_8025F620(callback,lbl_80378090);return result;
}



