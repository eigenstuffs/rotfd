#ifndef GAME_PLATFORM_POOL_INTERNAL_H
#define GAME_PLATFORM_POOL_INTERNAL_H
#include "Game/bitset_internal.h"
#include "GXTexture.h"
extern "C" int fn_80207B94(BitSet_80207EE8*,int,int);
struct PlatformPoolObject {
 char unknown00[0xC];void*image0C;void*palette10;char unknown14[0x18];
 int slot;u32 width30,height34;char unknown38[4];
 unsigned char format3C,unknown3D,paletteFormat3E,unknown3F[2],flags41;
};
struct PlatformPoolRecord {
 GXTexObj texture;GXTlutObj palette;GXTexObj extra;PlatformPoolObject*object;
 signed char flag50,palette51,extra52;char unknown53;
};
template<class T> struct PlatformPoolStorage {
 int count,capacity;T*data;
 PlatformPoolStorage():count(0),capacity(0),data(0){}
 void clear(){if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}
 ~PlatformPoolStorage(){if(data){clear();data=0;}}
};
struct PlatformPoolCore : PlatformPoolStorage<PlatformPoolRecord> {
 BitSet_80207EE8 occupied;int limit,used;
 const u32&word(int i){u32*base=occupied.data;return base[i];}
 signed char test(int i){return (word(i>>5)&(1UL<<(i&31)))?1:0;}
 void release(int i){
  if(test(i)){u32 mask=1UL<<(i&31);u32 w=occupied.data[i>>5];w&=~mask;occupied.data[i>>5]=w;--used;}
 }
 int first(){if(limit==0)return -1;return fn_80207B94(&occupied,1,0);}
 int next(int i){if(i+1>=limit)return -1;return fn_80207B94(&occupied,1,i+1);}
 PlatformPoolCore():limit(0),used(0){}
 ~PlatformPoolCore(){for(int i=0;i<limit;++i)release(i);}
};
struct PlatformPool_80281EA4 : PlatformPoolCore {
 PlatformPool_80281EA4();
 ~PlatformPool_80281EA4();
 static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};

typedef char CheckPlatformPoolRecord[sizeof(PlatformPoolRecord)==0x54?1:-1];
typedef char CheckPlatformPool[sizeof(PlatformPool_80281EA4)==0x24?1:-1];
#endif
