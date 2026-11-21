/* C fragment of Dolphin SDK OSContext.c, GSQE78.
 * Adapted from doldecomp/melee; see reference/melee-sdk/PROVENANCE.md.
 * Original context assembly routines remain fallback objects.
 */
#include "OSContext_abi.h"

OSContext* OSGetCurrentContext(void) {
  return (OSContext*)__OSCurrentContext;
}

