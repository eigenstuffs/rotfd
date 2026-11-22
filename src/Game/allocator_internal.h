#ifndef GAME_ALLOCATOR_INTERNAL_H
#define GAME_ALLOCATOR_INTERNAL_H

typedef unsigned int u32;
typedef struct AllocBlock AllocBlock;
typedef struct FreeBlock FreeBlock;
struct AllocBlock { u32 size; AllocBlock *prev,*next; };
struct FreeBlock { AllocBlock *prev_alloc; u32 size; FreeBlock *prev,*next; };
typedef struct Heap {
    AllocBlock *first_alloc,*last_alloc;
    FreeBlock *first_free,*last_free;
    unsigned char *arena_hi,*arena_lo,*limit;
    u32 free_bytes,allocations,padding,overhead;
} Heap;
extern Heap lbl_801EF5C8;
extern struct { unsigned char prefix[0x110]; void *reporter; } lbl_801E9D24;
extern const char lbl_802AD3D0[],lbl_802AD3EC[],lbl_802AD408[],lbl_802AD434[],lbl_802AD450[];
void fn_801EF5F4(void *out,const void *in,u32 bytes);
void fn_801EF610(Heap *self,void *memory);
void fn_801FA014(void *,const char *,...);
void *memset(void *,int,unsigned long);
AllocBlock *fn_801EF860(Heap *,int,unsigned int);
AllocBlock *fn_801EF6E0(Heap *,void *,int);
u32 fn_801EFCBC(u32,u32);

#endif
