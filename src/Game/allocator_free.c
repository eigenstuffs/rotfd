/* Recovered release/coalescing; not byte-matching yet. */
#include "allocator_internal.h"

void fn_801EF610(Heap *self,void *memory) {
    FreeBlock *next_free;
    AllocBlock *block;
    u32 size;
    AllocBlock *next_alloc;
    AllocBlock *prev_alloc;
    FreeBlock *result;
    FreeBlock *prev_free;
    block=(AllocBlock *)memory-1;
    next_free=self->first_free;
    prev_alloc=block->prev;
    next_alloc=block->next;
    size=block->size+sizeof(AllocBlock);
    result=(FreeBlock *)block;
    while(next_free<(FreeBlock *)block) next_free=next_free->next;
    prev_free=next_free->prev;
    prev_alloc->next=next_alloc;
    next_alloc->prev=prev_alloc;
    if(prev_free>(FreeBlock *)prev_alloc && prev_free!=self->first_free) {
        prev_free->size+=size;
        result=prev_free;
    } else {
        prev_free->next=result;
        next_free->prev=result;
        result->next=next_free;
        result->prev=prev_free;
        result->size=size;
        result->prev_alloc=prev_alloc;
    }
    if(next_free<(FreeBlock *)next_alloc && next_free!=self->last_free) {
        next_free->next->prev=result;
        result->next=next_free->next;
        result->size+=next_free->size;
    }
    --self->allocations;
    self->free_bytes+=size;
    self->overhead-=sizeof(AllocBlock);
}
