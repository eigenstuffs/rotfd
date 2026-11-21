/* Retained allocation release; see docs/notes/runtime-new.md. */
#pragma exceptions on
#pragma internal on
#include "exception_internal.h"
extern "C" void __msl_free(void*);
__declspec(weak) void operator delete(void* p) throw() {
    if (p) __msl_free(p);
}
