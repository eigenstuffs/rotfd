#ifndef GAME_PLATFORM_ARAM_LIFETIME_INTERNAL_H
#define GAME_PLATFORM_ARAM_LIFETIME_INTERNAL_H
#include "Game/bitset_internal.h"
template<class T> struct PlatformAramStorage {
    int count,capacity;T* data;
    PlatformAramStorage():count(0),capacity(0),data(0){}
    void clear(){if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}
    ~PlatformAramStorage(){if(data){clear();data=0;}}
};
struct PlatformAramPool : PlatformAramStorage<unsigned char> {
    BitSet_80207EE8 occupied;int limit,used;
    const u32& word(int i){u32* base=occupied.data;return base[i];}
    signed char test(int i){return(word(i>>5)&(1UL<<(i&31)))?1:0;}
    void release(int i){if(test(i)){u32 mask=1UL<<(i&31);u32 w=occupied.data[i>>5];w&=~mask;occupied.data[i>>5]=w;--used;}}
    int isOccupied(int i)const {if(i<0||i>=limit)return 0;return(occupied.data[i>>5]&(1UL<<(i&31)))?1:0;}
    PlatformAramPool():limit(0),used(0){}
    ~PlatformAramPool();
    static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
typedef char CheckPlatformAramPool[sizeof(PlatformAramPool)==36?1:-1];
#endif
