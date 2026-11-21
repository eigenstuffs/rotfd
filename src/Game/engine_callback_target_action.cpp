#include "Game/engine_callback_target_action.h"

/* The borrowed member-pointer pool retains its original data ownership. */
extern "C" {
extern const struct TargetActionMemberPool {
    char unknown00[0x18];
    TargetActionMemberPointer entries[5];
} lbl_802ECCD8;
extern const char lbl_802AEC4C[];
}


struct TargetKey {char unknown00[0x20];int key20;};
struct TargetFlags {char unknown00[0x38];unsigned long long flags38;};
template<class T>struct ActionEntry {T*object;unsigned long unknown04,unknown08;signed char generation;char unknown0D[3];};
template<class T>struct ActionManager {char unknown00[8];ActionEntry<T>*entries;};
struct ActionGlobals {char unknown00[0x118];ActionManager<TargetKey>*manager;};
extern "C" ActionGlobals lbl_801E9D24;
template<class T>static inline T*resolve(ActionManager<T>*m,const TargetActionHandle&h){ActionEntry<T>*entry=&m->entries[h.bits.index];return entry->generation==h.bits.tag?entry->object:0;}
static inline TargetFlags* resolveFlags(ActionManager<TargetKey>*manager,const TargetActionHandle&h){struct ByteManager{int count,capacity;char*entries;};ActionEntry<TargetFlags>*entry=(ActionEntry<TargetFlags>*)(((ByteManager*)manager)->entries+h.bits.index*16);return entry->generation==h.bits.tag?entry->object:0;}

extern "C" int fn_8025C858(TargetActionOwner* self, int event, TargetActionCallback* callback) {
    const TargetActionMemberPool* members = &lbl_802ECCD8;
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
