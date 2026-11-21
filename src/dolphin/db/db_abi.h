/* Private debug-interface ABI, adapted from the Melee SDK DBInterface.h. */
#ifndef ROTFD_DB_ABI_H
#define ROTFD_DB_ABI_H
#include "../os/OSContext_abi.h"
typedef struct DBInterface {
    u32 bPresent;
    u32 exceptionMask;
    void (*ExceptionDestination)(void);
    void *exceptionReturn;
} DBInterface;
extern DBInterface* __DBInterface;
extern BOOL DBVerbose;
extern void __DBExceptionDestination(void);
extern void OSDumpContext(OSContext*);
extern void PPCHalt(void);
#define OSPhysicalToCached(x) ((void*)((u32)(x) + 0x80000000))
#define OSCachedToPhysical(x) ((u32)(x) - 0x80000000)
#endif
