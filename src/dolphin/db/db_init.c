/* Dolphin SDK db.c C fragment, GSQE78.
 * Adapted from doldecomp/melee; see reference/melee-sdk/PROVENANCE.md.
 * The native exception-entry wrapper remains original fallback.
 */
#include "db_abi.h"

BOOL DBVerbose;
DBInterface* __DBInterface;

void DBInit(void)
{
    __DBInterface = OSPhysicalToCached(0x40);
    __DBInterface->ExceptionDestination =
        (void*) OSCachedToPhysical(__DBExceptionDestination);
    DBVerbose = 1;
}

void __DBExceptionDestinationAux(void)
{
    u32* contextAddr;
    OSContext* context;

    contextAddr = (void*) 0xC0;
    context = OSPhysicalToCached(*contextAddr);
    OSReport("DBExceptionDestination\n");
    OSDumpContext(context);
    PPCHalt();
}
