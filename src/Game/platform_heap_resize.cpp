// Resize through the arena or the observed fixed-size allocation pools.
#include "Game/platform_heap_pools_internal.h"
extern "C" void *fn_8028FAF4(PlatformHeap *self,void *memory,u32 oldSize,u32 newSize){
 if(oldSize>self->limit && newSize>self->limit)
  return fn_801EF83C(lbl_801EF5C8,memory,newSize,lbl_802AFB58,lbl_802AFB68,0x1e8);
 void *next=fn_8028FF24(self,newSize);
 memcpy(next,memory,newSize>oldSize?oldSize:newSize);
 self->release(memory,oldSize);
 return next;
}
