/* Dolphin SDK semaphore C functions, GSQE78.
 * Adapted from the public zeldaret/tp SDK reconstruction;
 * see reference/tp-sdk/PROVENANCE.md and docs/notes/OSSemaphore.md.
 */
#include "OSContext_abi.h"
typedef signed long s32;
struct OSThread;
typedef struct { struct OSThread *head, *tail; } OSThreadQueue;
typedef struct { s32 count; OSThreadQueue queue; } OSSemaphore;
extern void OSInitThreadQueue(OSThreadQueue *), OSSleepThread(OSThreadQueue *), OSWakeupThread(OSThreadQueue *);

void OSInitSemaphore(OSSemaphore* sem, s32 count) {
    BOOL enabled = OSDisableInterrupts();

    OSInitThreadQueue(&sem->queue);
    sem->count = count;
    OSRestoreInterrupts(enabled);
}

s32 OSWaitSemaphore(OSSemaphore* sem) {
    BOOL enabled;
    s32 count;

    enabled = OSDisableInterrupts();

    while((sem->count = (count = sem->count)) <= 0) {
        OSSleepThread(&sem->queue);
    }

    sem->count--;
    OSRestoreInterrupts(enabled);
    return count;
}

s32 OSSignalSemaphore(OSSemaphore* sem) {
    BOOL enabled;
    s32 count;

    enabled = OSDisableInterrupts();
    count = sem->count;
    sem->count++;

    OSWakeupThread(&sem->queue);
    OSRestoreInterrupts(enabled);
    return count;
}

