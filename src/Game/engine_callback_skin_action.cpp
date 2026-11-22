#include "Game/engine_callback_skin_action.h"

/* The borrowed member-pointer pool retains its original data ownership. */
extern "C" {
extern const struct SkinActionMemberPool {
    char unknown00[0x0C];
    SkinActionMemberPointer entries[5];
} lbl_802ECAB0;
extern const char lbl_802AEBF0[];
}

// Complete physical vtable view; original external identities are retained.
typedef void (*SkinActionVirtualSlot)();
struct SkinActionVtable {const void*typeInfo;long thisOffset;SkinActionVirtualSlot slots[29];};
extern "C" {
void __dt__23CallbackTailOwnerSecondFv();
void slot0C__13Root_80207414FUl();
void slot10__13Root_80207414Fv();
void slot14__13Root_80207414Fv();
void fn_8025885C();
void fn_80257C78();
void fn_8025A9E0();
void fn_8025A9E8();
void fn_8025A9F0();
void fn_8025AA5C();
void fn_802573E4();
void fn_80257338();
void fn_80258654();
void fn_80257FF0();
void fn_80257E04();
void fn_80257D20();
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
SkinActionVtable lbl_802ECAF8 = {0,0,{
    (SkinActionVirtualSlot)__dt__23CallbackTailOwnerSecondFv,
    (SkinActionVirtualSlot)slot0C__13Root_80207414FUl,
    (SkinActionVirtualSlot)slot10__13Root_80207414Fv,
    (SkinActionVirtualSlot)slot14__13Root_80207414Fv,
    (SkinActionVirtualSlot)fn_8025885C,
    (SkinActionVirtualSlot)fn_80257C78,
    (SkinActionVirtualSlot)fn_8025A9E0,
    (SkinActionVirtualSlot)fn_8025A9E8,
    (SkinActionVirtualSlot)fn_8025A9F0,
    (SkinActionVirtualSlot)fn_8025AA5C,
    (SkinActionVirtualSlot)fn_802573E4,
    (SkinActionVirtualSlot)fn_80257338,
    (SkinActionVirtualSlot)fn_80258654,
    (SkinActionVirtualSlot)fn_80257FF0,
    (SkinActionVirtualSlot)fn_80257E04,
    (SkinActionVirtualSlot)fn_80257D20,
    (SkinActionVirtualSlot)slot48__7Agent_ZFv,
    (SkinActionVirtualSlot)slot4C__7Agent_ZFv,
    (SkinActionVirtualSlot)slot50__7Agent_ZFv,
    (SkinActionVirtualSlot)slot54__7Agent_ZFv,
    (SkinActionVirtualSlot)slot58__7Agent_ZFv,
    (SkinActionVirtualSlot)slot5C__7Agent_ZFv,
    (SkinActionVirtualSlot)slot60__7Agent_ZFv,
    (SkinActionVirtualSlot)slot64__15AnimatedAgent_ZFv,
    (SkinActionVirtualSlot)slot68__15AnimatedAgent_ZFv,
    (SkinActionVirtualSlot)slot6C__7Agent_ZFv,
    (SkinActionVirtualSlot)slot70__7Agent_ZFv,
    (SkinActionVirtualSlot)slot74__15AnimatedAgent_ZFv,
    (SkinActionVirtualSlot)fn_8025ACF0
}};
}
typedef char SkinActionVtableSize[sizeof(SkinActionVtable)==124?1:-1];

extern "C" int fn_8025ACF0(SkinActionOwner* self, int event, SkinActionCallback* callback) {
    const SkinActionMemberPool* members = &lbl_802ECAB0;
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
        fn_8025F4F4(callback, 0, lbl_802AEBF0);
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
        fn_8025F694(callback,lbl_8037808C);
    case 8:
        break;
    case 11: {
        int ready=0;
        if(fn_8025E9FC(self,0x40)&&!fn_8025E9FC(self,0x3F))ready=1;
        result=ready;
        break;
    }
    case 12:
        fn_8023297C(resolve(lbl_801E9D24.manager,self->target64),&fn_80257B70(self,0),0,1);
        break;
    case 14:
        result=fn_8025E9FC(self,0x3F);
        break;
    case 15: {
        fn_802601C8(lbl_801E9D24.actions,self,0x40);
        SkinActionCopyHandle target(fn_80257B70(self,5));
        fn_8023297C(resolve(lbl_801E9D24.manager,self->target64),&target,0,1);
        fn_802073BC(self,0x40,self,resolve(lbl_801E9D24.manager,target)->value30,lbl_8037B520);
        break;
    }
    default:
        result=2;
        break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}
