#ifndef GAME_PLATFORM_CACHE_INTERNAL_H
#define GAME_PLATFORM_CACHE_INTERNAL_H
#include "world_curve_arrays_internal.h"
struct CacheKey {Handle_801F7F10 handle;unsigned short index,unknown6;~CacheKey(){}};
struct CacheNode:CacheKey {unsigned short prev,next;~CacheNode(){}};
struct CacheNodeList:WorldCurveArray<CacheNode>{~CacheNodeList(){}}
;
struct CacheBlock {void*data;u32 size,capacity,unknownC;void clear(){data=0;size=0;capacity=0;unknownC=0;}};
struct CacheStorage:CacheNodeList {
    int stride;CacheBlock*blocks;
    ~CacheStorage(){if(blocks)fn_801EF610(lbl_801EF5C8,blocks);}
};
struct CacheBase_802EA868:CacheStorage {
    virtual unsigned short bind(const Handle_801F7F10&,unsigned short);
    ~CacheBase_802EA868(){}
    static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
    CacheNode&at(unsigned int n){CacheNode*base=data;return base[n];}
    void unlink(unsigned int n){at(at(n).prev).next=at(n).next;at(at(n).next).prev=at(n).prev;}
    void prepend(unsigned int n){at(n).next=at(0).next;at(n).prev=0;at(at(0).next).prev=n;at(0).next=n;}

};
struct Cache10_802F1490:CacheBase_802EA868 {virtual unsigned short bind(const Handle_801F7F10&,unsigned short);~Cache10_802F1490();};
struct Cache900_802F149C:CacheBase_802EA868 {virtual unsigned short bind(const Handle_801F7F10&,unsigned short);~Cache900_802F149C();};

#endif
