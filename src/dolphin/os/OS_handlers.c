/* Dolphin SDK OS.c C fragment, GSQE78.
 * Adapted from pinned PrimeDecomp/prime; see reference/prime-sdk/PROVENANCE.md.
 */
#include "OS_abi.h"

extern __OSExceptionHandler* OSExceptionTable;

__OSExceptionHandler
    __OSSetExceptionHandler(__OSException exception, __OSExceptionHandler handler) {
  __OSExceptionHandler oldHandler;
  oldHandler = OSExceptionTable[exception];
  OSExceptionTable[exception] = handler;
  return oldHandler;
}

__OSExceptionHandler __OSGetExceptionHandler(__OSException exception) {
  return OSExceptionTable[exception];
}

