/* Local target ABI for the recovered C fragments of OSReset.c. */
#ifndef ROTFD_OSRESET_ABI_H
#define ROTFD_OSRESET_ABI_H
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

struct OSResetFunctionQueue {
    struct OSResetFunctionInfo * head;
    struct OSResetFunctionInfo * tail;
};

typedef BOOL (*OSResetFunction)(BOOL);

typedef struct OSResetFunctionInfo OSResetFunctionInfo;
struct OSResetFunctionInfo
{
    OSResetFunction func;
    u32 priority;
    OSResetFunctionInfo *next;
    OSResetFunctionInfo *prev;
};

extern struct OSResetFunctionQueue OSResetFunctionQueue;
extern void OSResetHardware(u32);
extern int __PADDisableRecalibration(int);
extern int OSDisableScheduler(void), OSEnableScheduler(void);
extern void __OSStopAudioSystem(void), LCDisable(void), ICFlashInvalidate(void);
extern void __OSReboot(u32, u32), OSCancelThread(OSThread *);
extern void *memset(void *, int, unsigned long);
extern BOOL __OSSyncSram(void), __OSUnlockSram(BOOL);
typedef struct OSSram {
    u16 checksum, checksumInv;
    u32 ead0, ead1;
    s32 counterBias;
    signed char displayOffsetH;
    u8 ntd, language, flags;
} OSSram;
extern OSSram *__OSLockSram(void);
OSThreadQueue __OSActiveThreadQueue : 0x800000DC;
volatile u16 __VIRegs[59] : 0xCC002000;
volatile u32 __PIRegs[12] : 0xCC003000;
#define ASSERTLINE(line,cond) ((void)0)
#endif
