#include "OSContext_abi.h"
typedef signed long s32;
typedef s32 OSPriority;

struct OSThread;
struct OSMutex;
struct OSMutexQueue;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue
{
    struct OSThread *head;
    struct OSThread *tail;
} OSThreadQueue;

typedef struct OSThreadLink
{
    struct OSThread *next;
    struct OSThread *prev;
} OSThreadLink;

typedef struct OSMutexQueue
{
    struct OSMutex *head;
    struct OSMutex *tail;
} OSMutexQueue;

typedef struct OSMutexLink
{
    struct OSMutex *next;
    struct OSMutex *prev;
} OSMutexLink;

typedef struct OSThread
{
    /*0x000*/ struct OSContext context;   
    /*0x2C8*/ u16 state;     
    /*0x2CA*/ u16 attr;      
    /*0x2CC*/ s32 suspend;   
    /*0x2D0*/ OSPriority priority;  
    /*0x2D4*/ OSPriority base;
    /*0x2D8*/ void *val;                          
    /*0x2DC*/ struct OSThreadQueue *queue;     
    /*0x2E0*/ struct OSThreadLink link;                    
    /*0x2E8*/ struct OSThreadQueue queueJoin;              
    /*0x2F0*/ struct OSMutex *mutex;     
    /*0x2F4*/ struct OSMutexQueue queueMutex;              
    /*0x2FC*/ struct OSThreadLink linkActive;             
    /*0x304*/ u8 *stackBase; 
    /*0x308*/ u32 *stackEnd;  
} OSThread;

typedef struct OSMutex
{
    /*0x00*/ OSThreadQueue queue;
    /*0x08*/ OSThread *thread;
    /*0x0C*/ s32 count;
    /*0x10*/ OSMutexLink link;
} OSMutex;


extern void OSInitThreadQueue(OSThreadQueue *), OSSleepThread(OSThreadQueue *), OSWakeupThread(OSThreadQueue *);
extern OSThread *OSGetCurrentThread(void);
extern void __OSPromoteThread(OSThread *, OSPriority);
extern OSPriority __OSGetEffectivePriority(OSThread *);
#define ASSERTMSGLINE(line,cond,msg) ((void)0)
#define ASSERTMSG2LINE(line,cond,msg,a,b) ((void)0)
#define ASSERTLINE(line,cond) ((void)0)

#define ENQUEUE_MUTEX(mutex, queue, link)        \
    do {                                         \
        struct OSMutex * __prev = (queue)->tail; \
        if (__prev == NULL) {                    \
            (queue)->head = (mutex);             \
        } else {                                 \
            __prev->link.next = (mutex);         \
        }                                        \
        (mutex)->link.prev = __prev;             \
        (mutex)->link.next = 0;                  \
        (queue)->tail = (mutex);                 \
    } while(0);

#define DEQUEUE_MUTEX(mutex, queue, link)             \
    do {                                              \
        struct OSMutex * __next = (mutex)->link.next; \
        struct OSMutex * __prev = (mutex)->link.prev; \
        if (__next == NULL) {                         \
            (queue)->tail = __prev;                   \
        } else {                                      \
            __next->link.prev = __prev;               \
        }                                             \
        if (__prev == NULL) {                         \
            (queue)->head = __next;                   \
        } else {                                      \
            __prev->link.next = __next;               \
        }                                             \
    } while(0);

#define DEQUEUE_HEAD(mutex, queue, link)            \
    do {                                            \
        struct OSMutex * __next = mutex->link.next; \
        if (__next == NULL) {                       \
            (queue)->tail = 0;                      \
        } else {                                    \
            __next->link.prev = 0;                  \
        }                                           \
        (queue)->head = __next;                     \
    } while(0);

void OSInitMutex(struct OSMutex * mutex) {
    OSInitThreadQueue(&mutex->queue);
    mutex->thread = 0;
    mutex->count = 0;
}

void OSLockMutex(struct OSMutex * mutex) {
    int enabled = OSDisableInterrupts();
    struct OSThread * currentThread = OSGetCurrentThread();

    ASSERTMSGLINE(0x8C, currentThread, "OSLockMutex(): current thread does not exist.");
    ASSERTMSGLINE(0x8E, currentThread->state == 2, "OSLockMutex(): current thread is not running.");
    
    while(1) {
        struct OSThread * ownerThread = mutex->thread;
        if (ownerThread == 0) {
            mutex->thread = currentThread;
            mutex->count++;
            ENQUEUE_MUTEX(mutex, &currentThread->queueMutex, link);
            break;
        } else if (ownerThread == currentThread) {
            mutex->count++;
            break;
        } else {
            currentThread->mutex = mutex;
            __OSPromoteThread(mutex->thread, currentThread->priority);
            ASSERTMSG2LINE(0xA4, __OSCheckDeadLock(currentThread) == 0, "OSLockMutex(): detected deadlock: current thread %p, mutex %p.", currentThread, mutex);
            OSSleepThread(&mutex->queue);
            currentThread->mutex = NULL;
        }
    }
    OSRestoreInterrupts(enabled);
}

void OSUnlockMutex(struct OSMutex * mutex) {
    int enabled = OSDisableInterrupts();
    struct OSThread * currentThread = OSGetCurrentThread();

    ASSERTMSGLINE(0xBD, currentThread, "OSUnlockMutex(): current thread does not exist.");
    ASSERTMSGLINE(0xBF, currentThread->state == 2, "OSUnlockMutex(): current thread is not running.");
    ASSERTMSG2LINE(0xC2, mutex->thread == currentThread, "OSUnlockMutex(): current thread %p is not the owner of mutex %p.", currentThread, mutex);

    if (mutex->thread == currentThread) {
        if(!--mutex->count) {
            DEQUEUE_MUTEX(mutex, &currentThread->queueMutex, link);
            mutex->thread = 0;

            if (currentThread->priority < currentThread->base) {
                currentThread->priority = __OSGetEffectivePriority(currentThread);
            }
            OSWakeupThread(&mutex->queue);
        }
    }
    OSRestoreInterrupts(enabled);
}

void __OSUnlockAllMutex(struct OSThread * thread) {
    struct OSMutex * mutex;

    while(thread->queueMutex.head) {
        mutex = thread->queueMutex.head;
        DEQUEUE_HEAD(mutex, &thread->queueMutex, link);
        ASSERTLINE(0xE5, mutex->thread == thread);
        mutex->count = 0;
        mutex->thread = 0;
        OSWakeupThread(&mutex->queue);
    }
}

