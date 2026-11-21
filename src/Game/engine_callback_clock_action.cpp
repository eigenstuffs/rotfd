#include "Game/engine_callback_clock_action.h"

/* The borrowed member-pointer pool retains its original data ownership. */
extern "C" {
extern const struct ClockActionMemberPool {
    char unknown00[0x54];
    ClockActionMemberPointer entries[5];
} lbl_802ECE30;
extern const char lbl_802AEC64[];
}

// Complete original physical vtable, retaining all external function identities.
typedef void (*ClockActionVirtualSlot)();
struct ClockActionVtable {const void*typeInfo;long thisOffset;ClockActionVirtualSlot slots[33];};
extern "C" {
void __dt__15Object_8003CC1CFv();
void slot0C__13Root_80207414FUl();
void slot10__13Root_80207414Fv();
void slot14__13Root_80207414Fv();
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
void fn_8025DB30();
void fn_8025D1C8();
void fn_8025D054();
void fn_800DDFDC();
void fn_800DE0CC();
ClockActionVtable lbl_802ECEC0 = {0,0,{
    (ClockActionVirtualSlot)__dt__15Object_8003CC1CFv,
    (ClockActionVirtualSlot)slot0C__13Root_80207414FUl,
    (ClockActionVirtualSlot)slot10__13Root_80207414Fv,
    (ClockActionVirtualSlot)slot14__13Root_80207414Fv,
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

extern "C" int fn_8025D874(ClockActionOwner* self, int event, ClockActionCallback* callback) {
    const ClockActionMemberPool* members = &lbl_802ECE30;
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
