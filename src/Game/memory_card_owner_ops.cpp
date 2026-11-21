#include "Game/memory_card_owner_internal.h"

extern "C" {
extern char lbl_80341038[];
int OSResumeThread(void*);
int OSSuspendThread(void*);
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSWakeupThread(void*);
int CARDProbe(int);
int strcmp(const char*, const char*);
char* strcpy(char*, const char*);
}

extern "C" signed char fn_802780BC(MemoryCardOwnerView* self, int channel)
{
    OSResumeThread(lbl_80341038);
    OSLockMutex(self->mutex);
    signed char result = CARDProbe(channel);
    OSUnlockMutex(self->mutex);
    if (!result)
        self->formatted = 0;
    OSSuspendThread(lbl_80341038);
    return result;
}

extern "C" unsigned long fn_80278138(MemoryCardOwnerView* self, const char* name)
{
    if (strcmp(name, self->name)) {
        OSLockMutex(self->mutex);
        strcpy(self->name, name);
        OSUnlockMutex(self->mutex);
    }
    unsigned long status = self->status;
    OSWakeupThread(self->queue);
    return status;
}
