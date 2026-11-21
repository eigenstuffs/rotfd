/* C fragment of Dolphin SDK OSContext.c, GSQE78.
 * Adapted from doldecomp/melee; see reference/melee-sdk/PROVENANCE.md.
 * Original context assembly routines remain fallback objects.
 */
#include "OSContext_abi.h"

extern char OSContextInitMessage[];
void __OSContextInit(void) {
  __OSSetExceptionHandler(__OS_EXCEPTION_FLOATING_POINT, OSSwitchFPUContext);
  __OSFPUContext = NULL;
  DBPrintf(OSContextInitMessage);
}

