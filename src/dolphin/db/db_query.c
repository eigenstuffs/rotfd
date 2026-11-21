/* Dolphin SDK db.c C fragment, GSQE78.
 * Adapted from doldecomp/melee; see reference/melee-sdk/PROVENANCE.md.
 */
#include "db_abi.h"

BOOL __DBIsExceptionMarked(__OSException exception)
{
    u32 mask = (1 << exception);
    return __DBInterface->exceptionMask & mask;
}

/* The original release function intentionally produces no output. */
void DBPrintf(char* str, ...) {}
