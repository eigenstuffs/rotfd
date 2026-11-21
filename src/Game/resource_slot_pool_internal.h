#ifndef GAME_RESOURCE_SLOT_POOL_INTERNAL_H
#define GAME_RESOURCE_SLOT_POOL_INTERNAL_H
#include "resource_slot_internal.h"
struct BitSet_80207EE8 {
    int count,capacity;u32* words;int bits;
    ~BitSet_80207EE8();
    const u32& word(int i){u32* base=words;return base[i];}
    signed char test(int i){return (word(i>>5)&(1UL<<(i&31)))?1:0;}
    void clear(int i){words[i>>5]&=~(1UL<<(i&31));}
    void set(int i){words[i>>5]|=1UL<<(i&31);}
};
struct SlotRecord {u32 name;int references;BitSet_80207EE8 occupied;WorldCurveArray<ResetHandle2> slots;~SlotRecord(){}
const int& size(){return slots.count;}
int vacant(){return fn_80207B94(&occupied,0,0);}
OwnerHandle& slot(int i){return slots.data[i];}
};
struct SlotManager {int count,capacity;SlotRecord* data;BitSet_80207EE8 occupied;int limit,live;
SlotRecord& at(int i){return data[i];}
void release(int record,SlotRecord* entry){
if(occupied.test(record)){
entry->~SlotRecord();
u32 mask=1UL<<(record&31);
u32 w=occupied.words[record>>5];
w&=~mask;occupied.words[record>>5]=w;
--live;
}
}
};
static inline bool same(const OwnerHandle&a,const OwnerHandle&b){Activable_Z* p=a.get();return p==b.get();}

typedef char CheckSlotRecord[sizeof(SlotRecord)==0x24?1:-1];
typedef char CheckSlotManager[sizeof(SlotManager)==0x24?1:-1];
typedef char CheckSlotBitset[sizeof(BitSet_80207EE8)==0x10?1:-1];
#endif
