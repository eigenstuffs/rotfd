/* Registration and event selectors for the native clock callback owner.
 * PMFs are genuine compiler constants. The ContainerBase/Pool/Handle view
 * follows the existing matching container_layer_initialization.cpp layout.
 * Deferred emission preserves native local constant and function ordering. */
#include "Game/clock_member_protocol.h"
typedef void (*ClockActionVirtualSlot)();
struct ClockActionVtable {const void*typeInfo;long thisOffset;ClockActionVirtualSlot slots[33];};
extern "C" {extern const char lbl_802AEC64[],lbl_802AEC74[];}
typedef unsigned long u32;
extern "C" {
    extern const char lbl_802EC720[],lbl_802ED000[];
    extern ClockActionVtable lbl_802ECEC0;
    extern unsigned long lbl_80378070;
    void fn_8025E5FC();
    void fn_8025E714(void *,const ClockMemberPointer &);
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

struct NativeClockResourceStorage:ContainerBase_802563CC {
 NativeClockResourceStorage(){vtable=lbl_802ED000;}
 ~NativeClockResourceStorage(){vtable=lbl_802ED000;}
};
struct NativeClockConstructStorage:NativeClockResourceStorage {
 NativeClockConstructStorage(NativeClockResourceStorage*owner){owner->vtable=&lbl_802ECEC0;}
 ~NativeClockConstructStorage(){}
};
struct NativeClockRegistration:NativeClockConstructStorage {
 LayerInitHandle1 first;int index;LayerInitHandle2 second;LayerInitHandle3 third;
 NativeClockRegistration():NativeClockConstructStorage(this){index=-1;flags|=0x100000ULL;}
 ~NativeClockRegistration(){vtable=&lbl_802ECEC0;}
};
inline void addClockMember(void*self,ClockMemberPointer member){fn_8025E714(self,member);}
extern "C" void fn_8025DE20(){
 lbl_80378070=0;
 fn_8025E5FC();
 NativeClockRegistration clock;
 addClockMember(&clock,&ClockMemberOwner::slot74);
 addClockMember(&clock,&ClockMemberOwner::slot78);
}
extern "C" int fn_8025DB30(ClockMemberOwner* self, int event, ClockMemberCallback* callback) {
    int result = 1;
    switch (event) {
    case 0:
        fn_8025EF34(self, &ClockMemberOwner::slot74, -1);
        return 1;
    case 1:
        fn_8025EEB4(self, &ClockMemberOwner::slot74);
        return 1;
    case 2:
        fn_8025EB70(self, &ClockMemberOwner::slot74);
        return 1;
    case 3:
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        callback = fn_8025F074(self, &ClockMemberOwner::slot74);
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        return 0;
    case 4:
        if (callback)
            return (signed char)(callback->flags28 & 1);
        callback = fn_8025F074(self, &ClockMemberOwner::slot74);
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
        fn_8025F4F4(callback, 0, lbl_802AEC74);
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
        self->slot7C((int)self->value2C);
        self->slot28(3);
        callback->flags28 &= 0xFFFB;
        break;
    default:
        result = 2;
        break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}
extern "C" int fn_8025D874(ClockMemberOwner* self, int event, ClockMemberCallback* callback) {
    int result = 1;
    switch (event) {
    case 0:
        fn_8025EF34(self, &ClockMemberOwner::slot78, -1);
        return 1;
    case 1:
        fn_8025EEB4(self, &ClockMemberOwner::slot78);
        return 1;
    case 2:
        fn_8025EB70(self, &ClockMemberOwner::slot78);
        return 1;
    case 3:
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        callback = fn_8025F074(self, &ClockMemberOwner::slot78);
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        return 0;
    case 4:
        if (callback)
            return (signed char)(callback->flags28 & 1);
        callback = fn_8025F074(self, &ClockMemberOwner::slot78);
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
        fn_8025F4F4(callback, 3, lbl_802AEC64);
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
        self->slot80();
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
void __dt__15Object_8003CC1CFv();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void fn_8025D6C4();
void fn_8025D3E0();
void fn_8025CDB0();
void fn_8025CDB8();
void fn_8025CDC0();
void fn_8025CE1C();
void fn_8025D4D0();
void fn_8025D4CC();
void fn_8025D5F4();
void fn_802560D8();
void fn_8003DCBC();
void fn_8002DAD8();
void fn_8002392C();
void fn_80023934();
void fn_8002393C();
void fn_80028D58();
void fn_80028D60();
void fn_80028D68();
void fn_80028D6C();
void fn_8002DADC();
void fn_8002DAE4();
void fn_80256028();
void fn_80023944();
void fn_8025D1C8();
void fn_8025D054();
void fn_800DDFDC();
void fn_800DE0CC();
ClockActionVtable lbl_802ECEC0 = {0,0,{
    (ClockActionVirtualSlot)__dt__15Object_8003CC1CFv,
    (ClockActionVirtualSlot)slot0C__12BaseObject_ZFUl,
    (ClockActionVirtualSlot)slot10__12BaseObject_ZFv,
    (ClockActionVirtualSlot)slot14__12BaseObject_ZFv,
    (ClockActionVirtualSlot)fn_8025D6C4,
    (ClockActionVirtualSlot)fn_8025D3E0,
    (ClockActionVirtualSlot)fn_8025CDB0,
    (ClockActionVirtualSlot)fn_8025CDB8,
    (ClockActionVirtualSlot)fn_8025CDC0,
    (ClockActionVirtualSlot)fn_8025CE1C,
    (ClockActionVirtualSlot)fn_8025D4D0,
    (ClockActionVirtualSlot)fn_8025D4CC,
    (ClockActionVirtualSlot)fn_8025D5F4,
    (ClockActionVirtualSlot)fn_802560D8,
    (ClockActionVirtualSlot)fn_8003DCBC,
    (ClockActionVirtualSlot)fn_8002DAD8,
    (ClockActionVirtualSlot)fn_8002392C,
    (ClockActionVirtualSlot)fn_80023934,
    (ClockActionVirtualSlot)fn_8002393C,
    (ClockActionVirtualSlot)fn_80028D58,
    (ClockActionVirtualSlot)fn_80028D60,
    (ClockActionVirtualSlot)fn_80028D68,
    (ClockActionVirtualSlot)fn_80028D6C,
    (ClockActionVirtualSlot)fn_8002DADC,
    (ClockActionVirtualSlot)fn_8002DAE4,
    (ClockActionVirtualSlot)fn_80256028,
    (ClockActionVirtualSlot)fn_80023944,
    (ClockActionVirtualSlot)fn_8025DB30,
    (ClockActionVirtualSlot)fn_8025D874,
    (ClockActionVirtualSlot)fn_8025D1C8,
    (ClockActionVirtualSlot)fn_8025D054,
    (ClockActionVirtualSlot)fn_800DDFDC,
    (ClockActionVirtualSlot)fn_800DE0CC
}};
}
typedef char ClockActionVtableSize[sizeof(ClockActionVtable)==140?1:-1];


typedef char NativeClockSizeCheck[sizeof(NativeClockRegistration)==0x70?1:-1];
typedef char NativeClockPMFSizeCheck[sizeof(ClockMemberPointer)==12?1:-1];
