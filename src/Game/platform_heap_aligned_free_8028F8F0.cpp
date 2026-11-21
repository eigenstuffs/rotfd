// Return an allocation, rounded up to the 32-byte pool granularity, to its
// arena or its fixed-size pool.
typedef unsigned long u32;
struct HeapPoolRecord { unsigned char *memory; unsigned char first, freeCount, reserved[2]; };
struct HeapSizePool {
 HeapSizePool *next, *previous; u32 size; unsigned char capacity, reserved[3];
 HeapPoolRecord *records; u32 count; HeapPoolRecord *current, *selected;
 inline void release(void *memory);
 inline HeapPoolRecord *locate(void *memory) {
  HeapPoolRecord *left=selected;
  u32 bytes=capacity*size;
  HeapPoolRecord *right=left+1;
  HeapPoolRecord *end=records+count;
  if(right==end)right=0;
  for(;;) {
   if(left) {
    if((unsigned char*)memory>=left->memory && (unsigned char*)memory<left->memory+bytes)return left;
    if(left==records)left=0;else --left;
   }
   if(right) {
    if((unsigned char*)memory>=right->memory && (unsigned char*)memory<right->memory+bytes)return right;
    ++right;
    if(right==end)right=0;
   }
  }

 }
};
struct PlatformHeap {u32 unknown; HeapSizePool *current,*pools; u32 unknownC[4]; u32 limit;inline void release(void *memory,const u32& size);};
extern "C" {extern char lbl_801EF5C8[];
void fn_801EF610(void*,void*);
void fn_8029091C(HeapSizePool*,void*);
}
inline void HeapSizePool::release(void *memory){selected=locate(memory);fn_8029091C(this,memory);}
inline void PlatformHeap::release(void *memory,const u32& size){
 if(size>limit)fn_801EF610(lbl_801EF5C8,memory);
 else {HeapSizePool *pool=current;
  if(pool && size==pool->size)pool->release(memory);
  else {pool=pools;while(pool && size!=pool->size)pool=pool->next;current=pool;current->release(memory);}
 }
}
extern "C" void fn_8028F8F0(PlatformHeap *self, void *memory, u32 size)
{
    self->release(memory, (size + 0x1F) & ~0x1F);
}
