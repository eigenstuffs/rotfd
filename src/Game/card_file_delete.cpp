#include "Game/memory_card_owner_internal.h"

extern "C" {
extern char lbl_80341038[];
extern const char lbl_802AF158[];
extern signed char lbl_80377FC9[1], lbl_80377FC0[1];
extern struct { char unknown00[0x110]; void* log; } lbl_801E9D24;
int OSGetResetSwitchState();
void fn_801FA014(void*, const char*, ...);
int CARDDelete(int, const char*);
extern char lbl_801EF5C8[];
int OSResumeThread(void*);
int OSSuspendThread(void*);
void OSLockMutex(void*);
void OSUnlockMutex(void*);
int CARDProbeEx(int, int*, unsigned long*);
int CARDUnmount(int);
int fn_80277918(MemoryCardOwnerView*, int);
void fn_801EF610(void*, void*);
}

static inline int deleteSucceeded(int result) {
    switch (result) {
    case 0:
    case -4:
        return 1;
    default:
        return 0;
    }
}

extern "C" int fn_8027857C(MemoryCardOwnerView* self, const char* name)
{
    const char* messages = lbl_802AF158;
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
    int attempts;
    int final = fn_80277918(self, 1);
    if (final == 0) {
        attempts = 0;
        lbl_80377FC9[0] = OSGetResetSwitchState();
        int open;
        do {
            open = CARDDelete(self->channel, name);
            ++attempts;
            if (!OSGetResetSwitchState() && lbl_80377FC9[0]) {
                fn_801FA014(lbl_801E9D24.log, messages + 0xF4);
                lbl_80377FC0[0] = 1;
            }
            lbl_80377FC9[0] = OSGetResetSwitchState();
            if (lbl_80377FC9[0])
                fn_801FA014(lbl_801E9D24.log, messages + 0x114);
        } while (open == -1 && attempts < 1000);
        if (attempts >= 1000)
            fn_801FA014(lbl_801E9D24.log, messages + 0x134);
        int success = deleteSucceeded(open);
        int mapped = 17;
        if (success)
            mapped = 0;
        final = mapped;
    }
    CARDUnmount(self->channel);
    if (self->workArea) {
        fn_801EF610(lbl_801EF5C8, self->workArea);
        self->workArea = 0;
    }
    OSUnlockMutex(self->mutex);
    OSSuspendThread(lbl_80341038);
    return final;
}

