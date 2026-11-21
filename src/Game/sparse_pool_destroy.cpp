#include "Game/bitset_internal.h"
#include "Game/typed_cleanup_tables.h"
struct Handle_801F7F10 { unsigned long value; ~Handle_801F7F10(); };
struct SparseDestroyZero1:Handle_801F7F10 {};
struct SparseDestroyHandle:SparseDestroyZero1 {};
struct SparseDestroyStorage {
    int count,capacity;SparseDestroyHandle* items;
    ~SparseDestroyStorage() {
        if(items) {
            if(items) {fn_8028FD50(lbl_8028F698,items,capacity*4);items=0;}
            items=0;
        }
    }
};
struct SparseDestroyBase:SparseDestroyStorage {
    BitSet_80207EE8 occupied;
    int limit,used;
    const unsigned long& word(int i)const {unsigned long* p=occupied.data;return p[i];}
    signed char test(int i)const { return (word(i>>5)&(1UL<<(i&31)))?1:0; }
    ~SparseDestroyBase() {
        for(int i=0;i<limit;++i) {
            if(test(i)) {
                items[static_cast<unsigned int>(i)].~SparseDestroyHandle();
                occupied.data[i>>5]&=~(1UL<<(i&31));
                --used;
            }
        }
    }
};
struct SparseDestroySelf:SparseDestroyBase {void* table;};
extern "C" SparseDestroySelf* fn_8026BD48(SparseDestroySelf* self,int deleting) {
    if(self) {
        self->table=&lbl_802ED168;
        self->SparseDestroyBase::~SparseDestroyBase();
        if((short)deleting>0)fn_801EF610(lbl_801EF5C8,self);
    }
    return self;
}
