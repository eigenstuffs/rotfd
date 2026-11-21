/* C fragment of Dolphin SDK OSContext.c, GSQE78.
 * Adapted from doldecomp/melee; see reference/melee-sdk/PROVENANCE.md.
 * Original context assembly routines remain fallback objects.
 */
#include "OSContext_abi.h"

void OSClearContext(register OSContext* context) {
  context->mode = 0;
  context->state = 0;
  if (context == __OSFPUContext)
    __OSFPUContext = NULL;
}

