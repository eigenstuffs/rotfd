// Memory-card format retry worker.
// See docs/notes/game-engine-card-format-worker.md.
#include "Game/engine_card_format_worker.h"
#include "Game/memory_card_owner_internal.h"
extern "C" {
extern char lbl_80341038[],lbl_801EF5C8[];
extern const char lbl_802AF158[];
extern signed char lbl_80377FC9[1], lbl_80377FC0[1], lbl_803780C0[1];
extern struct { char unknown00[0x110]; void* log; } lbl_801E9D24;
int OSResumeThread(void*);
int OSSuspendThread(void*);
void OSLockMutex(void*);
void OSUnlockMutex(void*);
int fn_80277918(MemoryCardOwnerView*, int);
int CARDProbeEx(int, int*, unsigned long*);
int CARDUnmount(int);
int CARDFormat(int);
int OSGetResetSwitchState();
void fn_801FA014(void*, const char*, ...);
void fn_801EF610(void*, void*);
}
extern "C" int fn_80277CB4(MemoryCardOwnerView* self) {
    const char* messages = (const char*)&lbl_802AF158;
    OSResumeThread(lbl_80341038);
    OSLockMutex(self->mutex);
    int result = fn_80277918(self, 0);
    if (result == 0 || result == 1) {
        int probe = -1;
        while (probe == -1)
            probe = CARDProbeEx(self->channel, &self->memorySize, &self->sectorSize);
        result = probe ? 0 : 1;
    }
    CARDUnmount(self->channel);
    if (self->workArea) {
        fn_801EF610(lbl_801EF5C8, self->workArea);
        self->workArea = 0;
    }
    if (result == 0) {
        OSUnlockMutex(self->mutex);
        OSSuspendThread(lbl_80341038);
        return 1;
    }
    lbl_803780C0[0] = 1;
    result = fn_80277918(self, 1);
    if (result == 0 || result == 3 || result == 21) {
        int attempts = 0;
        lbl_80377FC9[0] = OSGetResetSwitchState();
        int format;
        do {
            format = CARDFormat(self->channel);
            ++attempts;
            if (!OSGetResetSwitchState() && lbl_80377FC9[0]) {
                fn_801FA014(lbl_801E9D24.log, messages + 0xF4);
                lbl_80377FC0[0] = 1;
            }
            lbl_80377FC9[0] = OSGetResetSwitchState();
            if (lbl_80377FC9[0])
                fn_801FA014(lbl_801E9D24.log, messages + 0x114);
        } while (format == -1 && attempts < 1000);
        if (attempts >= 1000)
            fn_801FA014(lbl_801E9D24.log, messages + 0x134);
        self->formatted = 1;
        if (format == 0)
            result = 0;
        else if (format == -3)
            result = 1;
        else
            result = 15;
    }
    CARDUnmount(self->channel);
    if (self->workArea) {
        fn_801EF610(lbl_801EF5C8, self->workArea);
        self->workArea = 0;
    }
    lbl_803780C0[0] = 0;
    OSUnlockMutex(self->mutex);
    OSSuspendThread(lbl_80341038);
    return result;
}
