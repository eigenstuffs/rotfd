#include "resource_slot_internal.h"
extern "C" void fn_801E5724(ResetManager*self,OwnerHandle*handle){
    int i=fn_80207B94(&self->occupied,1,0);
    while(i>=0 && different(self->entries[i],*handle))i=fn_80207B94(&self->occupied,1,i+1);
    self->occupied.words[i>>5]^=1UL << (i&31);
    fn_80240120(target(*handle),0);
    target(*handle)->set10(ResetHandle2());
    target(*handle)->set1C(ResetHandle2());
    target(*handle)->set20(ResetHandle2());
    target(*handle)->set24(ResetHandle3());
    target(*handle)->set28(ResetHandle3());
    target(*handle)->set130(OwnerHandle());
    *handle=ResetHandle2();
}
