// Memory-card mount retry and result normalization.
// See docs/notes/game-engine-card-mount-worker.md.
#include "Game/engine_card_mount_worker.h"
#include "Game/memory_card_owner_internal.h"
extern "C" {
extern char lbl_801EF5C8[];
extern const char lbl_802AF158[];
extern signed char lbl_80377FC9[1], lbl_80377FC0[1];
extern struct { char unknown00[0x110]; void* log; } lbl_801E9D24;
int OSGetResetSwitchState();
int CARDMount(int, void*, void*);
int CARDCheck(int);
void fn_801FA014(void*, const char*, ...);
void* fn_801EFA1C(void*, unsigned long, const char*, const char*, int, int);
}
extern "C" int fn_80277918(MemoryCardOwnerView* self, int check) {
    const char* messages = (const char*)&lbl_802AF158;
    if (!self->workArea) {
        self->workArea = fn_801EFA1C(lbl_801EF5C8, 0xA000, messages + 0x4C, messages + 0x5C, 0x39E, 32);
        if (!self->workArea)
            return 13;
    }
    int attempts = 0;
    lbl_80377FC9[0] = OSGetResetSwitchState();
    int result;
    do {
        result = CARDMount(self->channel, self->workArea, 0);
        ++attempts;
        if (!OSGetResetSwitchState() && lbl_80377FC9[0]) {
            fn_801FA014(lbl_801E9D24.log, messages + 0xF4);
            lbl_80377FC0[0] = 1;
        }
        lbl_80377FC9[0] = OSGetResetSwitchState();
        if (lbl_80377FC9[0])
            fn_801FA014(lbl_801E9D24.log, messages + 0x114);
    } while (result == -1 && attempts < 1000);
    if (attempts >= 1000)
        fn_801FA014(lbl_801E9D24.log, messages + 0x134);
    switch (result) {
    case -13:
        result = 21;
        break;
    case -5:
        result = 23;
        break;
    case -6: {
        int checkAttempts = 0;
        lbl_80377FC9[0] = OSGetResetSwitchState();
        do {
            result = CARDCheck(self->channel);
            ++checkAttempts;
            if (!OSGetResetSwitchState() && lbl_80377FC9[0]) {
                fn_801FA014(lbl_801E9D24.log, messages + 0xF4);
                lbl_80377FC0[0] = 1;
            }
            lbl_80377FC9[0] = OSGetResetSwitchState();
            if (lbl_80377FC9[0])
            fn_801FA014(lbl_801E9D24.log, messages + 0x114);
        } while (result == -1 && checkAttempts < 1000);
        if (checkAttempts >= 1000)
            fn_801FA014(lbl_801E9D24.log, messages + 0x134);
        if (result == -6) {
            if (!self->formatted)
                result = 3;
            else
                result = 23;
        }
        if (result == -5)
            result = 23;
        if (result == 0)
            result = 0;
        break;
    }
    case 0:
        result = 0;
        if ((signed char)check && self->sectorSize != 0x2000)
            return 22;
        break;
    case -2:
        result = 20;
        break;
    default:
        result = 1;
        if (self->connected) {
            self->state = 1;
            self->connected = 0;
        }
        break;
    }
    return result;
}
