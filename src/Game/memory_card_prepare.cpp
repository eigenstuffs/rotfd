#include "Game/memory_card_owner_internal.h"

extern "C" {
extern char lbl_80341038[];
extern char lbl_801EF5C8[];
int OSResumeThread(void*);
int OSSuspendThread(void*);
void OSLockMutex(void*);
void OSUnlockMutex(void*);
int CARDProbeEx(int, int*, unsigned long*);
int CARDUnmount(int);
int fn_80277918(MemoryCardOwnerView*, int);
int fn_802776D0(MemoryCardOwnerView*);
void fn_801EF610(void*, void*);
}

extern "C" int fn_80278338(MemoryCardOwnerView* self)
{
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
        return 1;
    }
    int final = fn_80277918(self, 1);
    CARDUnmount(self->channel);
    if (self->workArea) {
        fn_801EF610(lbl_801EF5C8, self->workArea);
        self->workArea = 0;
    }
    OSUnlockMutex(self->mutex);
    OSSuspendThread(lbl_80341038);
    return final;
}

extern "C" void fn_80278454(MemoryCardOwnerView* self)
{
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
        return;
    }
    if (fn_80277918(self, 1) == 0)
        fn_802776D0(self);
    CARDUnmount(self->channel);
    if (self->workArea) {
        fn_801EF610(lbl_801EF5C8, self->workArea);
        self->workArea = 0;
    }
    OSUnlockMutex(self->mutex);
    OSSuspendThread(lbl_80341038);
}
