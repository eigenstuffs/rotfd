#ifndef GAME_RESOURCE_SLOT_LIFETIME_INTERNAL_H
#define GAME_RESOURCE_SLOT_LIFETIME_INTERNAL_H
#include "resource_slot_pool_internal.h"
extern "C" void __ct__15BitSet_80207EE8Fv(void*);
template<class T> struct SlotRecordStorage {
    int count,capacity;T* data;
    void freeStorage(){if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}
    ~SlotRecordStorage(){if(data){freeStorage();data=0;}}
};
struct SlotPool_801E6FB0 : SlotRecordStorage<SlotRecord> {
    BitSet_80207EE8 occupied;int limit,live;
    SlotPool_801E6FB0(){count=0;capacity=0;data=0;__ct__15BitSet_80207EE8Fv(&occupied);limit=0;live=0;}
    ~SlotPool_801E6FB0();
    SlotRecord& at(int i){return data[i];}
    signed char release(int i){
        if(occupied.test(i)){
            data[i].~SlotRecord();
            u32 mask=1UL<<(i&31);
            u32 w=occupied.words[i>>5];
            w&=~mask;occupied.words[i>>5]=w;
            --live;
            return 1;
        }
        return 0;
    }
    void clear(){for(int i=0;i<limit;++i)release(i);}
    static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
struct SlotResource_802EA810 {
    SlotPool_801E6FB0 pool;
    WorldCurveArray<ResetHandle2> extra;
    BitSet_80207EE8 extraOccupied;
    SlotResource_802EA810();
    virtual ~SlotResource_802EA810();
    static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
typedef char CheckSlotPoolSize[sizeof(SlotPool_801E6FB0)==0x24?1:-1];
typedef char CheckSlotResourceSize[sizeof(SlotResource_802EA810)==0x44?1:-1];
#endif
