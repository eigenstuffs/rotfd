#include "Game/single_member_protocol.h"
struct ResolvedIndexVtable {const void*typeInfo;long thisOffset;void(*slots[29])();};
extern "C" ResolvedIndexVtable lbl_802ECA18;

typedef unsigned long u32;
extern "C" {
    extern const char lbl_802EC720[],lbl_802EC798[],lbl_802ED000[];
    extern char lbl_8028F698[];
    extern int lbl_80378050;
    void fn_8028FD50(void*,void*,int);
    void fn_80258948();
}
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct SingleStartupHandle1:Handle_801F7F10 {
    SingleStartupHandle1(){
        value=0;
    }
    ~SingleStartupHandle1(){
    }
};
struct SingleStartupHandle2:SingleStartupHandle1 {
    SingleStartupHandle2(){
        value=0;
    }
    ~SingleStartupHandle2(){
    }
};
struct SingleStartupHandle3:SingleStartupHandle2 {
    SingleStartupHandle3(){
        value=0;
    }
    ~SingleStartupHandle3(){
    }
};
// Partial layout views preserve the native construction and unused backup chain.
struct Object_8025F0D8 {
    u32 unknown[2];
    const void*vtable;
    char unknown0C[0x2C];
    unsigned long long flags;
    char unknown40[8];
    ~Object_8025F0D8();
};
struct SingleStartupElement {
    u32 value;
    ~SingleStartupElement(){
    }
};
struct SingleStartupPool {
    int size,capacity;
    SingleStartupElement*data;
    ~SingleStartupPool(){
        if(data){
            for(int i=0;i<size;i++)data[i].~SingleStartupElement();
            if(data){
                fn_8028FD50(lbl_8028F698,data,capacity*4);
                data=0;
            }
            data=0;
        }
    }
};
struct ContainerBase_802563CC:Object_8025F0D8 {
    SingleStartupPool pool;
    int unknown54;
    SingleStartupHandle2 handle58;
    char unknown5C[4];
    ContainerBase_802563CC();
    ~ContainerBase_802563CC(){
        vtable=lbl_802EC720;
    }
};
struct SingleStartupResource:ContainerBase_802563CC {
    SingleStartupResource(){
        vtable=lbl_802ED000;
    }
    ~SingleStartupResource(){
        vtable=lbl_802ED000;
    }
};
struct CallbackPair_802EC798:SingleStartupResource {
    SingleStartupHandle2 handle60;
    SingleStartupHandle3 handle64;
    int index68;
    CallbackPair_802EC798();
    ~CallbackPair_802EC798(){vtable=lbl_802EC798;}
};
// The empty vtable layer leaves the member receiver live through construction.
struct SingleStartupVtable {
    SingleStartupVtable(CallbackPair_802EC798* owner) {
        owner->vtable = &lbl_802ECA18;
    }
};
// The existing external destructor consumes this common prefix with flag -1.
struct Object_80021064:CallbackPair_802EC798,SingleStartupVtable {
    SingleStartupHandle3 handle70;
    Object_80021064():SingleStartupVtable(this) { flags |= 1ULL; }
    ~Object_80021064();
};
typedef char SingleStartupPairSize[(sizeof(CallbackPair_802EC798)==0x70)?1:-1];
typedef char SingleStartupObjectSize[(sizeof(Object_80021064)==0x78)?1:-1];
extern "C" void fn_8025E714(void*,const ResolvedIndexMemberPointer&);
extern "C" void fn_8025A930() {
    lbl_80378050 = 0;
    fn_80258948();
    Object_80021064 temporary;
    ResolvedIndexMemberPointer callback = &SingleCallbackPMFView::slot78;
    fn_8025E714(&temporary, callback);
}

extern "C" const char lbl_802AEBE4[];
struct ResolvedIndexEntry {ResolvedIndexTarget*object;unsigned long unknown04,unknown08;signed char generation;char unknown0D[3];};
struct ResolvedIndexManager {char unknown00[8];ResolvedIndexEntry*entries;};
struct ResolvedIndexGlobals {char unknown00[0x118];ResolvedIndexManager*manager;};
extern "C" ResolvedIndexGlobals lbl_801E9D24;
static inline ResolvedIndexTarget*resolve(ResolvedIndexManager*m,const ResolvedIndexHandle&h){ResolvedIndexEntry*e=&m->entries[h.bits.index];return e->generation==h.bits.tag?e->object:0;}

extern "C" int fn_8025A5F8(ResolvedIndexOwner* self, int event, ResolvedIndexCallback* callback) {
    int result = 1;
    switch (event) {
    case 0:
        fn_8025EF34(self, &SingleCallbackPMFView::slot78, -1);
        return 1;
    case 1:
        fn_8025EEB4(self, &SingleCallbackPMFView::slot78);
        return 1;
    case 2:
        fn_8025EB70(self, &SingleCallbackPMFView::slot78);
        return 1;
    case 3:
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        callback = fn_8025F074(self, &SingleCallbackPMFView::slot78);
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        return 0;
    case 4:
        if (callback)
            return (signed char)(callback->flags28 & 1);
        callback = fn_8025F074(self, &SingleCallbackPMFView::slot78);
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
        fn_8025F4F4(callback, 0, lbl_802AEBE4);
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
        result=0;
        if(fn_8025E9FC(self,0x42)){signed char present=(fn_801F7EB8(&self->target70)!=0);if(present)result=1;}
        break;
    case 15:
        resolve(lbl_801E9D24.manager,self->target70)->slotF4((int)self->value2C);
        break;
    default:
        result = 2;
        break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}
// Complete original physical vtable, retaining all external function identities.
typedef void (*ResolvedIndexVirtualSlot)();
extern "C" {
void __dt__15Object_80021064Fv();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void fn_8025A48C();
void fn_80259F0C();
void fn_80259DEC();
void fn_80259DF4();
void fn_80259DFC();
void fn_80259E68();
void fn_8025A244();
void fn_8025A190();
void fn_80258654();
void fn_8025A324();
void fn_8025A0A4();
void fn_80259FB4();
void fn_8002392C();
void fn_80023934();
void fn_8002393C();
void fn_80028D58();
void fn_80028D60();
void fn_80028D68();
void fn_80028D6C();
void fn_80257C58();
void fn_80257C50();
void fn_80256028();
void fn_80023944();
void fn_80023928();
ResolvedIndexVtable lbl_802ECA18 = {0,0,{
    (ResolvedIndexVirtualSlot)__dt__15Object_80021064Fv,
    (ResolvedIndexVirtualSlot)slot0C__12BaseObject_ZFUl,
    (ResolvedIndexVirtualSlot)slot10__12BaseObject_ZFv,
    (ResolvedIndexVirtualSlot)slot14__12BaseObject_ZFv,
    (ResolvedIndexVirtualSlot)fn_8025A48C,
    (ResolvedIndexVirtualSlot)fn_80259F0C,
    (ResolvedIndexVirtualSlot)fn_80259DEC,
    (ResolvedIndexVirtualSlot)fn_80259DF4,
    (ResolvedIndexVirtualSlot)fn_80259DFC,
    (ResolvedIndexVirtualSlot)fn_80259E68,
    (ResolvedIndexVirtualSlot)fn_8025A244,
    (ResolvedIndexVirtualSlot)fn_8025A190,
    (ResolvedIndexVirtualSlot)fn_80258654,
    (ResolvedIndexVirtualSlot)fn_8025A324,
    (ResolvedIndexVirtualSlot)fn_8025A0A4,
    (ResolvedIndexVirtualSlot)fn_80259FB4,
    (ResolvedIndexVirtualSlot)fn_8002392C,
    (ResolvedIndexVirtualSlot)fn_80023934,
    (ResolvedIndexVirtualSlot)fn_8002393C,
    (ResolvedIndexVirtualSlot)fn_80028D58,
    (ResolvedIndexVirtualSlot)fn_80028D60,
    (ResolvedIndexVirtualSlot)fn_80028D68,
    (ResolvedIndexVirtualSlot)fn_80028D6C,
    (ResolvedIndexVirtualSlot)fn_80257C58,
    (ResolvedIndexVirtualSlot)fn_80257C50,
    (ResolvedIndexVirtualSlot)fn_80256028,
    (ResolvedIndexVirtualSlot)fn_80023944,
    (ResolvedIndexVirtualSlot)fn_80023928,
    (ResolvedIndexVirtualSlot)fn_8025A5F8
}};
}
typedef char ResolvedIndexVtableSize[sizeof(ResolvedIndexVtable)==124?1:-1];

