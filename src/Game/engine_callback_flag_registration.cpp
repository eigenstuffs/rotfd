/* Registration and event selectors for the native target flag owner.
 * PMFs are genuine compiler constants. The ContainerBase/Pool/Handle view
 * follows the existing matching container_layer_initialization.cpp layout.
 * Deferred emission preserves native local constant and function ordering. */
#include "Game/flag_member_protocol.h"
typedef void (*TargetMatchVirtualSlot)();
struct TargetMatchVtable {const void*typeInfo;long thisOffset;TargetMatchVirtualSlot slots[33];};
extern "C" {extern const char lbl_802AEC4C[];}
typedef unsigned long u32;
extern "C" {
    extern const char lbl_802EC720[];
    extern TargetMatchVtable lbl_802ECD68;
    extern unsigned long lbl_80378068;
    void fn_8025E714(void *,const FlagMemberMemberPointer &);
    extern char lbl_8028F698[];
    extern int lbl_80378020;
    void fn_8028FD50(void*,void*,int);
    void fn_80256448();
}
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct LayerInitHandle1:Handle_801F7F10 {
    LayerInitHandle1(){
        value=0;
    }
    ~LayerInitHandle1(){
    }
};
struct LayerInitHandle2:LayerInitHandle1 {
    LayerInitHandle2(){
        value=0;
    }
    ~LayerInitHandle2(){
    }
};
struct LayerInitHandle3:LayerInitHandle2 {
    LayerInitHandle3(){
        value=0;
    }
    ~LayerInitHandle3(){
    }
};
struct Object_8025F0D8 {
    u32 unknown[2];
    const void*vtable;
    char unknown0C[0x2C];
    unsigned long long flags;
    char unknown40[8];
    ~Object_8025F0D8();
};
struct Element {
    u32 value;
    ~Element(){
    }
};
struct LayerInitPool {
    int size,capacity;
    Element*data;
    ~LayerInitPool(){
        if(data){
            for(int i=0;
            i<size;
            i++)data[i].~Element();
            if(data){
                fn_8028FD50(lbl_8028F698,data,capacity*4);
                data=0;
            }
            data=0;
        }
    }
};
struct ContainerBase_802563CC:Object_8025F0D8 {
    LayerInitPool pool;
    int unknown54;
    LayerInitHandle2 handle58;
    char unknown5C[4];
    ContainerBase_802563CC();
    ~ContainerBase_802563CC(){
        vtable=lbl_802EC720;
    }
};

struct NativeFlagVtableStorage {
 NativeFlagVtableStorage(ContainerBase_802563CC*owner){owner->vtable=&lbl_802ECD68;}
};
struct NativeFlagRegistration:ContainerBase_802563CC,NativeFlagVtableStorage {
 LayerInitHandle3 handle60;
 NativeFlagRegistration():NativeFlagVtableStorage(this){flags|=0x400ULL;}
 ~NativeFlagRegistration(){vtable=&lbl_802ECD68;}
};
inline void addFlagMember(void*self,FlagMemberMemberPointer member){fn_8025E714(self,member);}
extern "C" void fn_8025CC04(){
 lbl_80378068=0;
 fn_80256448();
 NativeFlagRegistration object;
 addFlagMember(&object,&FlagMemberOwner::slot84);
 addFlagMember(&object,&FlagMemberOwner::slot88);
}
struct TargetKey {char unknown00[0x20];int key20;};
struct TargetFlags {char unknown00[0x38];unsigned long long flags38;};
template<class T>struct ActionEntry {T*object;unsigned long unknown04,unknown08;signed char generation;char unknown0D[3];};
template<class T>struct ActionManager {char unknown00[8];ActionEntry<T>*entries;};
struct ActionGlobals {char unknown00[0x118];ActionManager<TargetKey>*manager;};
extern "C" ActionGlobals lbl_801E9D24;
template<class T>static inline T*resolve(ActionManager<T>*m,const FlagMemberHandle&h){ActionEntry<T>*entry=&m->entries[h.bits.index];return entry->generation==h.bits.tag?entry->object:0;}
static inline TargetFlags* resolveFlags(ActionManager<TargetKey>*manager,const FlagMemberHandle&h){struct ByteManager{int count,capacity;char*entries;};ActionEntry<TargetFlags>*entry=(ActionEntry<TargetFlags>*)(((ByteManager*)manager)->entries+h.bits.index*16);return entry->generation==h.bits.tag?entry->object:0;}

extern "C" int fn_8025C858(FlagMemberOwner* self, int event, FlagMemberCallback* callback) {
    int result = 1;
    switch (event) {
    case 0:
        fn_8025EF34(self, &FlagMemberOwner::slot84, -1);
        return 1;
    case 1:
        fn_8025EEB4(self, &FlagMemberOwner::slot84);
        return 1;
    case 2:
        fn_8025EB70(self, &FlagMemberOwner::slot84);
        return 1;
    case 3:
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        callback = fn_8025F074(self, &FlagMemberOwner::slot84);
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        return 0;
    case 4:
        if (callback)
            return (signed char)(callback->flags28 & 1);
        callback = fn_8025F074(self, &FlagMemberOwner::slot84);
        if (callback)
            return (signed char)(callback->flags28 & 1);
        return 0;
    case 5:
        return 1;
    case 6:
        if (callback)
            return callback->index2A;
        return -9999;
    }

    lbl_8037808C = 0;
    lbl_80378090 = 0;
    lbl_80378094 = -1;
    if (event == 8 || event == 7)
        fn_8025F4F4(callback, 0, lbl_802AEC4C);
    if (event == 11 && callback->index2A == -1)
        return 1;
    fn_8025F658(callback, lbl_80378090);
    int action;
    if (event >= 14)
        action = event + callback->index2A * 2;
    else
        action = event;
    switch (action) {
    case 7:
        fn_8025F694(callback, lbl_8037808C);
    case 8:
        break;
    case 14:
        result = fn_8025E9FC(self, 0x1E);
        break;
    case 15:
        if ((int)self->value2C != resolve(lbl_801E9D24.manager,self->slot78(-1))->key20)
            return 0;
        if (resolveFlags(lbl_801E9D24.manager,self->target28)->flags38 & 0x200000ULL)
            return 0;
        self->slot30();
        break;
    default:
        result = 2;
        break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}
extern "C" int fn_8025C520(FlagMemberOwner* self, int event, FlagMemberCallback* callback) {
    int result = 1;
    switch (event) {
    case 0:
        fn_8025EF34(self, &FlagMemberOwner::slot88, -1);
        return 1;
    case 1:
        fn_8025EEB4(self, &FlagMemberOwner::slot88);
        return 1;
    case 2:
        fn_8025EB70(self, &FlagMemberOwner::slot88);
        return 1;
    case 3:
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        callback = fn_8025F074(self, &FlagMemberOwner::slot88);
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        return 0;
    case 4:
        if (callback)
            return (signed char)(callback->flags28 & 1);
        callback = fn_8025F074(self, &FlagMemberOwner::slot88);
        if (callback)
            return (signed char)(callback->flags28 & 1);
        return 0;
    case 5:
        return 1;
    case 6:
        if (callback)
            return callback->index2A;
        return -9999;
    }

    lbl_8037808C = 0;
    lbl_80378090 = 0;
    lbl_80378094 = -1;
    if (event == 8 || event == 7)
        fn_8025F4F4(callback, 0, lbl_802AEC4C);
    if (event == 11 && callback->index2A == -1)
        return 1;
    fn_8025F658(callback, lbl_80378090);
    int action;
    if (event >= 14)
        action = event + callback->index2A * 2;
    else
        action = event;
    switch (action) {
    case 7:
        fn_8025F694(callback, lbl_8037808C);
    case 8:
        break;
    case 14:
        result = fn_8025E9FC(self, 0x1F);
        break;
    case 15:
        if ((int)self->value2C == resolve(lbl_801E9D24.manager,self->slot78(-1))->key20)
            self->slot34();
        break;
    default:
        result = 2;
        break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}
// Complete original physical vtable, retaining all external function identities.
extern "C" {
void __dt__15Object_8002CFCCFv();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void fn_8025C3B4();
void fn_8025C080();
void fn_8025BD64();
void fn_8025BD6C();
void fn_8025BD74();
void fn_8025BDC0();
void fn_8025C208();
void fn_8025C12C();
void fn_8025C2E4();
void slot3C__7Agent_ZFv();
void fn_8025BE2C();
void fn_8002DAD8();
void slot48__7Agent_ZFv();
void slot4C__7Agent_ZFv();
void slot50__7Agent_ZFv();
void slot54__7Agent_ZFv();
void slot58__7Agent_ZFv();
void slot5C__7Agent_ZFv();
void slot60__7Agent_ZFv();
void slot64__7Agent_ZFv();
void slot68__7Agent_ZFv();
void slot6C__7Agent_ZFv();
void slot70__7Agent_ZFv();
void fn_8002DA24();
void fn_8002DA2C();
void fn_8025BFF8();
void fn_8002DA34();
TargetMatchVtable lbl_802ECD68 = {0,0,{
    (TargetMatchVirtualSlot)__dt__15Object_8002CFCCFv,
    (TargetMatchVirtualSlot)slot0C__12BaseObject_ZFUl,
    (TargetMatchVirtualSlot)slot10__12BaseObject_ZFv,
    (TargetMatchVirtualSlot)slot14__12BaseObject_ZFv,
    (TargetMatchVirtualSlot)fn_8025C3B4,
    (TargetMatchVirtualSlot)fn_8025C080,
    (TargetMatchVirtualSlot)fn_8025BD64,
    (TargetMatchVirtualSlot)fn_8025BD6C,
    (TargetMatchVirtualSlot)fn_8025BD74,
    (TargetMatchVirtualSlot)fn_8025BDC0,
    (TargetMatchVirtualSlot)fn_8025C208,
    (TargetMatchVirtualSlot)fn_8025C12C,
    (TargetMatchVirtualSlot)fn_8025C2E4,
    (TargetMatchVirtualSlot)slot3C__7Agent_ZFv,
    (TargetMatchVirtualSlot)fn_8025BE2C,
    (TargetMatchVirtualSlot)fn_8002DAD8,
    (TargetMatchVirtualSlot)slot48__7Agent_ZFv,
    (TargetMatchVirtualSlot)slot4C__7Agent_ZFv,
    (TargetMatchVirtualSlot)slot50__7Agent_ZFv,
    (TargetMatchVirtualSlot)slot54__7Agent_ZFv,
    (TargetMatchVirtualSlot)slot58__7Agent_ZFv,
    (TargetMatchVirtualSlot)slot5C__7Agent_ZFv,
    (TargetMatchVirtualSlot)slot60__7Agent_ZFv,
    (TargetMatchVirtualSlot)slot64__7Agent_ZFv,
    (TargetMatchVirtualSlot)slot68__7Agent_ZFv,
    (TargetMatchVirtualSlot)slot6C__7Agent_ZFv,
    (TargetMatchVirtualSlot)slot70__7Agent_ZFv,
    (TargetMatchVirtualSlot)fn_8002DA24,
    (TargetMatchVirtualSlot)fn_8002DA2C,
    (TargetMatchVirtualSlot)fn_8025BFF8,
    (TargetMatchVirtualSlot)fn_8002DA34,
    (TargetMatchVirtualSlot)fn_8025C858,
    (TargetMatchVirtualSlot)fn_8025C520
}};
}
typedef char TargetMatchVtableSize[sizeof(TargetMatchVtable)==140?1:-1];


typedef char NativeFlagSizeCheck[sizeof(NativeFlagRegistration)==0x68?1:-1];

typedef char NativeFlagPMFSizeCheck[sizeof(FlagMemberMemberPointer)==12?1:-1];
