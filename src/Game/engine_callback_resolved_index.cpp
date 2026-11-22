#include "Game/engine_callback_resolved_index.h"

/* The borrowed member-pointer pool retains its original data ownership. */
extern "C" {
extern const struct ResolvedIndexMemberPool {
    char unknown00[0x0C];
    ResolvedIndexMemberPointer entries[5];
} lbl_802EC9D0;
extern const char lbl_802AEBE4[];
}


struct ResolvedIndexEntry {ResolvedIndexTarget*object;unsigned long unknown04,unknown08;signed char generation;char unknown0D[3];};
struct ResolvedIndexManager {char unknown00[8];ResolvedIndexEntry*entries;};
struct ResolvedIndexGlobals {char unknown00[0x118];ResolvedIndexManager*manager;};
extern "C" ResolvedIndexGlobals lbl_801E9D24;
static inline ResolvedIndexTarget*resolve(ResolvedIndexManager*m,const ResolvedIndexHandle&h){ResolvedIndexEntry*e=&m->entries[h.bits.index];return e->generation==h.bits.tag?e->object:0;}

// Complete original physical vtable, retaining all external function identities.
typedef void (*ResolvedIndexVirtualSlot)();
struct ResolvedIndexVtable {const void*typeInfo;long thisOffset;ResolvedIndexVirtualSlot slots[29];};
extern "C" {
void __dt__15Object_80021064Fv();
void slot0C__13Root_80207414FUl();
void slot10__13Root_80207414Fv();
void slot14__13Root_80207414Fv();
void fn_8025A48C();
void slot1C__13MovingAgent_ZFv();
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
void slot48__7Agent_ZFv();
void slot4C__7Agent_ZFv();
void slot50__7Agent_ZFv();
void slot54__7Agent_ZFv();
void slot58__7Agent_ZFv();
void slot5C__7Agent_ZFv();
void slot60__7Agent_ZFv();
void slot64__15AnimatedAgent_ZFv();
void slot68__15AnimatedAgent_ZFv();
void slot6C__7Agent_ZFv();
void slot70__7Agent_ZFv();
void slot74__15AnimatedAgent_ZFv();
ResolvedIndexVtable lbl_802ECA18 = {0,0,{
    (ResolvedIndexVirtualSlot)__dt__15Object_80021064Fv,
    (ResolvedIndexVirtualSlot)slot0C__13Root_80207414FUl,
    (ResolvedIndexVirtualSlot)slot10__13Root_80207414Fv,
    (ResolvedIndexVirtualSlot)slot14__13Root_80207414Fv,
    (ResolvedIndexVirtualSlot)fn_8025A48C,
    (ResolvedIndexVirtualSlot)slot1C__13MovingAgent_ZFv,
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
    (ResolvedIndexVirtualSlot)slot48__7Agent_ZFv,
    (ResolvedIndexVirtualSlot)slot4C__7Agent_ZFv,
    (ResolvedIndexVirtualSlot)slot50__7Agent_ZFv,
    (ResolvedIndexVirtualSlot)slot54__7Agent_ZFv,
    (ResolvedIndexVirtualSlot)slot58__7Agent_ZFv,
    (ResolvedIndexVirtualSlot)slot5C__7Agent_ZFv,
    (ResolvedIndexVirtualSlot)slot60__7Agent_ZFv,
    (ResolvedIndexVirtualSlot)slot64__15AnimatedAgent_ZFv,
    (ResolvedIndexVirtualSlot)slot68__15AnimatedAgent_ZFv,
    (ResolvedIndexVirtualSlot)slot6C__7Agent_ZFv,
    (ResolvedIndexVirtualSlot)slot70__7Agent_ZFv,
    (ResolvedIndexVirtualSlot)slot74__15AnimatedAgent_ZFv,
    (ResolvedIndexVirtualSlot)slot78__13MovingAgent_ZFv
}};
}
typedef char ResolvedIndexVtableSize[sizeof(ResolvedIndexVtable)==124?1:-1];

extern "C" int slot78__13MovingAgent_ZFv(ResolvedIndexOwner* self, int event, ResolvedIndexCallback* callback) {
    const ResolvedIndexMemberPool* members = &lbl_802EC9D0;
    int result = 1;
    switch (event) {
    case 0:
        fn_8025EF34(self, members->entries[0], -1);
        return 1;
    case 1:
        fn_8025EEB4(self, members->entries[1]);
        return 1;
    case 2:
        fn_8025EB70(self, members->entries[2]);
        return 1;
    case 3:
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        callback = fn_8025F074(self, members->entries[3]);
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        return 0;
    case 4:
        if (callback)
            return (signed char)(callback->flags28 & 1);
        callback = fn_8025F074(self, members->entries[4]);
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
