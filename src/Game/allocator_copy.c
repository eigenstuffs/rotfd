/* Word copy used when an arena allocation must move. */
#include "allocator_internal.h"

void fn_801EF5F4(void *out,const void *in,u32 bytes)
{
    u32 offset=0;
    do {
        *(u32 *)((u32)out+offset)=*(const u32 *)((u32)in+offset);
        offset+=4;
    } while(offset<bytes);
}
