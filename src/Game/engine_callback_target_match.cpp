#include "Game/engine_callback_target_match.h"

/* The borrowed member-pointer pool retains its original data ownership. */
extern "C" {
extern const struct TargetMatchMemberPool {
    char unknown00[0x54];
    TargetMatchMemberPointer entries[5];
} lbl_802ECCD8;
extern const char lbl_802AEC4C[];
}


struct TargetKey {char unknown00[0x20];int key20;};
template<class T>struct ActionEntry {T*object;unsigned long unknown04,unknown08;signed char generation;char unknown0D[3];};
template<class T>struct ActionManager {char unknown00[8];ActionEntry<T>*entries;};
struct ActionGlobals {char unknown00[0x118];ActionManager<TargetKey>*manager;};
extern "C" ActionGlobals lbl_801E9D24;
template<class T>static inline T*resolve(ActionManager<T>*m,const TargetMatchHandle&h){ActionEntry<T>*entry=&m->entries[h.bits.index];return entry->generation==h.bits.tag?entry->object:0;}

// Complete original physical vtable, retaining all external function identities.
typedef void (*TargetMatchVirtualSlot)();
struct TargetMatchVtable {const void*typeInfo;long thisOffset;TargetMatchVirtualSlot slots[33];};
extern "C" {
void __dt__15Object_8002CFCCFv();
void slot0C__13Root_80207414FUl();
void slot10__13Root_80207414Fv();
void slot14__13Root_80207414Fv();
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
void fn_8025C858();
TargetMatchVtable lbl_802ECD68 = {0,0,{
    (TargetMatchVirtualSlot)__dt__15Object_8002CFCCFv,
    (TargetMatchVirtualSlot)slot0C__13Root_80207414FUl,
    (TargetMatchVirtualSlot)slot10__13Root_80207414Fv,
    (TargetMatchVirtualSlot)slot14__13Root_80207414Fv,
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

extern "C" int fn_8025C520(TargetMatchOwner* self, int event, TargetMatchCallback* callback) {
    const TargetMatchMemberPool* members = &lbl_802ECCD8;
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
