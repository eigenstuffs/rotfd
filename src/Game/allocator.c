/* Game arena allocator: retained resize, allocation and initialization. */
#include "allocator_internal.h"

const char lbl_802AD3D0[] = "Unrecoverable fatal error";
const char lbl_802AD3EC[] = "Unable to allocate %d bytes";
const char lbl_802AD408[] = "Out of memory allocating memory of size %d";
const char lbl_802AD434[] = "FreeBloc[ %d ]->Size = %d";
const char lbl_802AD450[] = "Failing!  Size = %d, align = %d, heapsize = %d";

void fn_801EFAC4(Heap *self)
{
    FreeBlock *initial;
    self->limit=self->arena_hi-64000;
    self->free_bytes=self->limit-self->arena_lo;
    memset(self->arena_lo,13,self->free_bytes);
    self->first_alloc=(AllocBlock *)(((u32)self->arena_lo+31)&~31);
    self->first_alloc->size=0;
    self->last_alloc=(AllocBlock *)(((u32)self->limit-13)&~31);
    self->last_alloc->size=0;
    self->first_alloc->next=self->last_alloc;
    self->first_alloc->prev=0;
    self->last_alloc->prev=self->first_alloc;
    self->last_alloc->next=0;
    self->first_free=(FreeBlock *)((char *)(self->first_alloc+1)+((self->first_alloc->size+31)&~31));
    self->first_free->size=0;
    self->first_free->prev_alloc=0;
    self->last_free=(FreeBlock *)self->last_alloc-1;
    self->last_free->size=0;
    self->last_free->prev_alloc=0;
    initial=self->first_free+1;
    initial->size=(char *)self->last_free-(char *)initial;
    initial->prev_alloc=0;
    initial->next=self->last_free;
    initial->prev=self->first_free;
    self->first_free->prev=0;
    self->first_free->next=initial;
    self->last_free->prev=initial;
    self->last_free->next=0;
    initial->prev_alloc=self->first_alloc;
    self->allocations=0;
    self->free_bytes=initial->size;
    self->padding=0;
    self->overhead=0;
}

Heap *fn_801EFA7C(Heap *self,short flag)
{
    if(self && flag>0) fn_801EF610(&lbl_801EF5C8,self);
    return self;
}

void *fn_801EFA1C(Heap *self,int requested,const char *label,
                 const char *filename,int line,int alignment)
{
    unsigned int available=self->free_bytes;
    if(requested+32>available) {
        fn_801FA014(lbl_801E9D24.reporter,lbl_802AD450,requested,32,available);
        for(;;) {}
    }
    return fn_801EF860(self,requested,32)+1;
}

AllocBlock *fn_801EF860(Heap *self,int requested,unsigned int alignment) {
    u32 size=(requested+31)&~31;
    u32 padding;
    u32 total;
    u32 header=size+sizeof(AllocBlock);
    FreeBlock *free=self->first_free->next;
    AllocBlock *prev;
    u32 unused;
    while(free) {
        padding=(((u32)free+sizeof(AllocBlock)+31)&~31)-(u32)free-sizeof(AllocBlock);
        total=header+padding;
        unused=free->size-total;
        if((int)unused>=0) {
        AllocBlock *block;
        prev=free->prev_alloc;
        block=(AllocBlock *)((char *)free+padding);
        if(unused<sizeof(AllocBlock)) {
            size+=unused;
            free->next->prev=free->prev;
            free->prev->next=free->next;
        } else {
            FreeBlock *rest=(FreeBlock *)((char *)free+total);
            u32 remaining=free->size-(header)-padding;
            free->prev->next=rest;
            free->next->prev=rest;
            rest->next=free->next;
            rest->prev=free->prev;
            rest->size=remaining;
            rest->prev_alloc=block;
        }
        if(padding) prev->size+=padding;
        block->size=size;
        block->next=prev->next;
        block->prev=prev;
        prev->next=block;
        block->next->prev=block;
        ++self->allocations;
        self->free_bytes-=total;
        self->overhead+=sizeof(AllocBlock);
        self->padding+=padding+block->size-requested;
        return block;
        }
        free=free->next;
    }
    {
        FreeBlock *entry;
        int index;
        fn_801FA014(lbl_801E9D24.reporter,lbl_802AD408,requested);
        for(entry=self->first_free->next,index=0;entry;entry=entry->next) {
            fn_801FA014(lbl_801E9D24.reporter,lbl_802AD434,index,entry->size);
            ++index;
        }
        return 0;
    }
}

void *fn_801EF83C(Heap *self,void *memory,int requested) { return fn_801EF6E0(self,memory,requested)+1; }

AllocBlock *fn_801EF6E0(Heap *self,void *memory,int requested)
{
    AllocBlock *block=(AllocBlock *)memory-1;
    u32 size=(requested+31)&~31;
    u32 delta=block->size-size;
    if(delta<=sizeof(AllocBlock)) return block;
    {
        if((int)delta>0) {
            FreeBlock *next,*split;
            block->size=size;
            split=(FreeBlock *)((char *)(block+1)+size);
            next=self->first_free;
            while(next<(FreeBlock *)block) next=next->next;
            split->size=delta;
            split->prev_alloc=block;
            split->prev=next->prev;
            split->next=next;
            next->prev=split;
            split->prev->next=split;
            if(next<(FreeBlock *)block->next && next!=self->last_free) {
                next->next->prev=split;
                split->next=next->next;
                split->size+=next->size;
            }
            self->free_bytes+=delta;
            return block;
        } else {
            AllocBlock *replacement=fn_801EF860(self,requested,32);
            if(!replacement) {
                fn_801FA014(lbl_801E9D24.reporter,lbl_802AD3D0);
                fn_801FA014(lbl_801E9D24.reporter,lbl_802AD3EC,requested);
            }
            fn_801EF5F4(replacement+1,memory,fn_801EFCBC(replacement->size,block->size));
            fn_801EF610(self,memory);
            return replacement;
        }
    }
    return block;
}
