// Return an allocation to its arena or its observed fixed-size pool.
#include "Game/platform_heap_pools_internal.h"
extern "C" void fn_8028FD50(PlatformHeap *self, void *memory, u32 size)
{
    self->release(memory, size);
}
