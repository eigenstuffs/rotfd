/* Mutable target state. The nine-byte flag extent and the initialized
 * exception marker follow the original MetroTRK object layout. */
#include "targimpl_abi.h"

__declspec(section ".data") ProcessorRestoreFlags_PPC gTRKRestoreFlags = { 0 };
__declspec(section ".data") TRKExceptionStatus gTRKExceptionStatus = { { 0, 0, 0 }, 1, 0 };
__declspec(section ".data") TRKStepStatus gTRKStepStatus = { 0 };

typedef char RestoreFlagsSizeCheck[sizeof(ProcessorRestoreFlags_PPC) == 9 ? 1 : -1];
typedef char ExceptionStatusSizeCheck[sizeof(TRKExceptionStatus) == 16 ? 1 : -1];
typedef char StepStatusSizeCheck[sizeof(TRKStepStatus) == 20 ? 1 : -1];
