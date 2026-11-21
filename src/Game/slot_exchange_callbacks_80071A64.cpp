/* KelpBall translation-unit tail: the runtime base list, method tables and
 * pooled member-pointer constants (.data 0x802B7700..0x802B7998, formerly
 * native_rtti_base_lists_802B7700.cpp) together with the grid slot callback
 * dispatcher fn_80071A64, whose two switch tables the compiler emits between
 * them (0x802B791C is 4 mod 8, so they cannot be owned separately).
 * The member-pointer pool is defined in one namespace and viewed through an
 * extern declaration in another, so the dispatcher's copies are compiled as
 * reads of unknown external data, as in the original. */
#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for KelpBall.
NativeRuntimeBaseList<10> lbl_802B7700 = {
    {
        { &lbl_80374798, 0 }, // BaseObject_Z
        { &lbl_803747A0, 0 }, // ABC_Agent
        { &lbl_803747A8, 0 }, // Agent_Z
        { &lbl_803747B0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803747B8, 0 }, // AnimatedAgent_Z
        { &lbl_803747C0, 0 }, // MovingAgent_Z
        { &lbl_803747C8, 0 }, // Throwable_Z
        { &lbl_803747D0, 0 }, // LodAgent_Z
        { &lbl_803747D8, 0 }, // CActorAgent
        { &lbl_803747E0, 0 }, // CRBObjBaseAgent
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void fn_8002390C();
void fn_80023914();
void fn_8002391C();
void fn_80023920();
void fn_80023924();
void fn_80023928();
void fn_8002392C();
void fn_80023944();
void fn_80025E04();
void fn_80025E08();
void fn_80025E0C();
void fn_80025E10();
void fn_80025E18();
void fn_80025E1C();
void fn_8002BE80();
void fn_8002CEE8();
void fn_8002CEF8();
void fn_8006F2E0();
void fn_8006F35C();
void fn_8006F42C();
void fn_8006F44C();
void fn_8006F598();
void fn_8006F5B8();
void fn_8006F6CC();
void fn_8006F978();
void fn_8006FA04();
void fn_8006FC3C();
void fn_80070E54();
void fn_80070F44();
void fn_80071188();
void fn_80071190();
void fn_80071198();
void fn_800711D8();
void fn_80071224();
void fn_8007122C();
void fn_80256028();
void fn_80257C50();
void fn_80257C58();
void fn_80259F0C();
void fn_8025A190();
void fn_8025A244();
void fn_8025A324();
void fn_8025A5F8();
void fn_8025B448();
void fn_8025B928();
void fn_8025BAD4();
void fn_8025BAF4();
void fn_8025BB14();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802B7754[46] __attribute__((aligned(4))) = {
    &lbl_80374800,
    0,
    (const void*)fn_8006F978,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8006FA04,
    (const void*)fn_80259F0C,
    (const void*)fn_80071188,
    (const void*)fn_80071190,
    (const void*)fn_80071198,
    (const void*)fn_800711D8,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_8006FC3C,
    (const void*)fn_8025A324,
    (const void*)fn_8006F44C,
    (const void*)fn_8006F598,
    (const void*)fn_8002392C,
    (const void*)fn_8002CEE8,
    (const void*)fn_8002CEF8,
    (const void*)fn_8025BAF4,
    (const void*)fn_8025BAD4,
    (const void*)fn_8002390C,
    (const void*)fn_80023914,
    (const void*)fn_80257C58,
    (const void*)fn_80257C50,
    (const void*)fn_80256028,
    (const void*)fn_80023944,
    (const void*)fn_80023928,
    (const void*)fn_8025A5F8,
    (const void*)fn_8025B448,
    (const void*)fn_8025BB14,
    (const void*)fn_8002391C,
    (const void*)fn_80023920,
    (const void*)fn_80023924,
    (const void*)fn_8025B928,
    (const void*)fn_80025E04,
    (const void*)fn_80025E08,
    (const void*)fn_80025E0C,
    (const void*)fn_80025E10,
    (const void*)fn_80025E18,
    (const void*)fn_80025E1C,
    (const void*)fn_8002BE80,
    (const void*)fn_8006F6CC,
    (const void*)fn_8006F5B8,
};

extern "C" __declspec(section ".data") const void* const lbl_802B780C[47] __attribute__((aligned(4))) = {
    &lbl_803747E0,
    0,
    (const void*)fn_8006F2E0,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8006F35C,
    (const void*)fn_80259F0C,
    (const void*)fn_80071224,
    (const void*)fn_8007122C,
    (const void*)fn_80070E54,
    (const void*)fn_80070F44,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_8006F42C,
    (const void*)fn_8025A324,
    (const void*)fn_8006F44C,
    (const void*)fn_8006F598,
    (const void*)fn_8002392C,
    (const void*)fn_8002CEE8,
    (const void*)fn_8002CEF8,
    (const void*)fn_8025BAF4,
    (const void*)fn_8025BAD4,
    (const void*)fn_8002390C,
    (const void*)fn_80023914,
    (const void*)fn_80257C58,
    (const void*)fn_80257C50,
    (const void*)fn_80256028,
    (const void*)fn_80023944,
    (const void*)fn_80023928,
    (const void*)fn_8025A5F8,
    (const void*)fn_8025B448,
    (const void*)fn_8025BB14,
    (const void*)fn_8002391C,
    (const void*)fn_80023920,
    (const void*)fn_80023924,
    (const void*)fn_8025B928,
    (const void*)fn_80025E04,
    (const void*)fn_80025E08,
    (const void*)fn_80025E0C,
    (const void*)fn_80025E10,
    (const void*)fn_80025E18,
    (const void*)fn_80025E1C,
    (const void*)fn_8002BE80,
    (const void*)fn_8006F6CC,
    (const void*)fn_8006F5B8,
    0,
};

namespace pooled_member_pointers {
extern "C" __declspec(section ".data") const void* const lbl_802B78C8[3] __attribute__((aligned(4))) = {
    0,
    (const void*)0x00000078,
    (const void*)0x00000008,
};

extern "C" __declspec(section ".data") const void* const lbl_802B78D4[18] __attribute__((aligned(4))) = {
    0,
    (const void*)0x00000080,
    (const void*)0x00000008,
    0,
    (const void*)0x00000080,
    (const void*)0x00000008,
    0,
    (const void*)0x00000080,
    (const void*)0x00000008,
    0,
    (const void*)0x00000080,
    (const void*)0x00000008,
    0,
    (const void*)0x00000080,
    (const void*)0x00000008,
    0,
    (const void*)0x00000080,
    (const void*)0x00000008,
};
}


// Grid slot owner callback dispatcher: generic member-callback events 0-6,
// then per-action handling (query, reset, slot exchange with the neighbor
// found by fn_80072468). exchange() mirrors fn_80071904, which the original
// auto-inlined here; switch jump tables are compiler-generated .data.
typedef unsigned long u32;
struct MemberPointer{u32 a,b,c;};
struct Callback{char opaque00[0x28];unsigned short flags28;short index2A;};

struct SlotExchangeNode;
struct SlotExchangeHandle {
    union {
        unsigned long value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct SlotExchangeEntry {
    SlotExchangeNode* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
};
struct SlotExchangeManager {
    int count, capacity;
    SlotExchangeEntry* entries;
};
struct BorrowedSlotExchangeManager {
    SlotExchangeManager* value;
    BorrowedSlotExchangeManager(SlotExchangeManager* manager) : value(manager) {}
    SlotExchangeManager* operator->() const { return value; }
};
struct SlotExchangeContext {
    char unknown00[0x118];
    SlotExchangeManager* manager;
    BorrowedSlotExchangeManager getManager() {
        return BorrowedSlotExchangeManager(manager);
    }
};
extern "C" SlotExchangeContext lbl_801E9D24;

struct SlotExchangeVector {
    float x, y, z;
    SlotExchangeVector& operator=(const SlotExchangeVector& other) {
        x = other.x; y = other.y; z = other.z;
        return *this;
    }
};
struct SlotExchangeNode {
    char unknown00[0x70];
    SlotExchangeHandle controller;
    char unknown74[0x1E];
    short slot;
    char unknown94[0xD4];
    char operations[0x34];
    SlotExchangeVector position;
};
inline SlotExchangeNode* resolveSlotExchange(const SlotExchangeHandle& handle) {
    SlotExchangeEntry* entry =
        &lbl_801E9D24.getManager()->entries[handle.bits.index];
    if (entry->generation == handle.bits.generation) return entry->object;
    return 0;
}
struct SlotExchangeRecord {
    short id;
    SlotExchangeNode* node;
    SlotExchangeVector position;
    void setNode(SlotExchangeNode* next) { node = next; node->slot = id; }
    SlotExchangeNode* getNode() const { return node; }
};
struct BorrowedSlotExchangeNode {
    SlotExchangeNode* value;
    BorrowedSlotExchangeNode(SlotExchangeNode* node) : value(node) {}
    operator SlotExchangeNode*() const { return value; }
};
extern "C" {
void fn_8007340C(SlotExchangeNode*, SlotExchangeRecord*);
signed char fn_8007D6A0(void*, int);
}
struct SlotExchangeOwner {
    char unknown00[0x64];
    short column;
    short unknown66;
    short index;
    short unknown6A;
    int mode;
    signed char busy;
    char flag71;
    char unknown72[2];
    SlotExchangeRecord records[9];
    int slots[4][17];
    signed char exchange(SlotExchangeNode* node) {
        if (!busy) {
            short oldSlot = node->slot;
            SlotExchangeRecord& record = records[index];
            SlotExchangeNode* old = record.getNode();
            resolveSlotExchange(node->controller)->position = record.position;
            fn_8007340C(node, &records[index]);
            fn_8007D6A0(resolveSlotExchange(node->controller)->operations, 1);
            records[index].setNode(node);
            records[oldSlot].setNode(old);
            busy = 1;
            return 1;
        }
        return 0;
    }
    int currentSlot() const { return slots[mode][column]; }
    bool isEmpty() const { return currentSlot() < 0; }
    SlotExchangeNode* currentNode() { SlotExchangeRecord&rec=records[currentSlot()]; return rec.node; }
    void reset();
};

extern "C" {
}
namespace slot_exchange_view {
extern "C" const struct Pool{char opaque00[0x18];MemberPointer entries[5];}lbl_802B78C8;
}
using slot_exchange_view::Pool;
using slot_exchange_view::lbl_802B78C8;
extern "C" {
extern u32 lbl_8037808C,lbl_80378090;extern int lbl_80378094;
extern const float lbl_803788FC, lbl_80378900;
void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);
Callback*fn_8025F074(void*,MemberPointer);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,u32);void fn_8025F620(Callback*,u32);
signed char fn_8025E9FC(SlotExchangeOwner*,int);
signed char fn_80072468(SlotExchangeOwner*,SlotExchangeNode*);
void fn_802073BC(SlotExchangeOwner*,int,SlotExchangeOwner*,float,float);
}

inline void SlotExchangeOwner::reset(){
    flag71=0;
    for(unsigned i=0;i<9;i++)fn_8007D6A0(resolveSlotExchange(records[i].node->controller)->operations,3);
}
extern "C" int fn_80071A64(SlotExchangeOwner*self,int event,Callback*callback){
const Pool*members=&lbl_802B78C8;int result=1;
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
case 7:fn_8025F694(callback,lbl_8037808C);
case 8:break;
case 9:result=fn_8025E9FC(self,0x9C);break;
case 10:self->flag71=1;break;
case 14:result=!self->isEmpty();break;
case 15:{
    SlotExchangeNode*node=self->currentNode();
    if(fn_80072468(self,node)){
        if(self->exchange(node))self->column++;
    }
    fn_802073BC(self,0,self,lbl_803788FC,lbl_80378900);
    break;}
case 11:result=self->isEmpty();break;
case 12:{
    self->reset();
    callback->flags28&=0xFFFB;
    break;}
default:result=2;break;
}
fn_8025F620(callback,lbl_80378090);return result;
}

#pragma force_active on
extern "C" __declspec(section ".data") const void* const lbl_802B795C[15] __attribute__((aligned(4))) = {
    0,
    (const void*)0x00000078,
    (const void*)0x00000008,
    0,
    (const void*)0x00000078,
    (const void*)0x00000008,
    0,
    (const void*)0x00000078,
    (const void*)0x00000008,
    0,
    (const void*)0x00000078,
    (const void*)0x00000008,
    0,
    (const void*)0x00000078,
    (const void*)0x00000008,
};
#pragma force_active reset


