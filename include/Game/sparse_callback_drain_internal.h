#ifndef GAME_SPARSE_CALLBACK_DRAIN_INTERNAL_H
#define GAME_SPARSE_CALLBACK_DRAIN_INTERNAL_H

typedef unsigned long u32;
struct Handle {union{u32 value;struct{signed int generation:8;signed int index:24;}bits;};};
struct ObjectStorage{char unknown00[8];};
struct Object:ObjectStorage {
 virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void callback(void*);
 char unknown0C[0x14];Handle related;
};
struct Entry{Object*object;int unknown04,unknown08;signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct Manager{int count,capacity;Entry*entries;};
extern "C" {extern struct{char unknown00[0x118];Manager*manager;}lbl_801E9D24;}
static inline Object*resolved(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();return generation==h.bits.generation?m->entries[index].object:0;}
struct BitSet{int count,capacity;u32*data;int bits;};
extern "C" int fn_80207B94(BitSet*,int,int);
struct Record{Object*object;void*context;float elapsed,duration;};
struct Pool{
 int count,capacity;Record*data;BitSet occupied;int limit,used;
 Record&operator[](int i){return data[i];}
 const u32&word(int i){u32*base=occupied.data;return base[i];}
 signed char test(int i){return (word(i>>5)&(1UL<<(i&31)))?1:0;}
 void release(int i){if(test(i)){u32 mask=1UL<<(i&31);u32 w=occupied.data[i>>5];w&=~mask;occupied.data[i>>5]=w;--used;}}

};
struct View{char unknown00[0xC170];Pool records;int first(){if(records.limit==0)return -1;return fn_80207B94(&records.occupied,1,0);}int next(int i){if(i+1>=records.limit)return -1;return fn_80207B94(&records.occupied,1,i+1);}};

typedef char CheckSparseCallbackHandle[sizeof(Handle)==4?1:-1];
typedef char CheckSparseCallbackRecord[sizeof(Record)==16?1:-1];
typedef char CheckSparseCallbackBits[sizeof(BitSet)==16?1:-1];
typedef char CheckSparseCallbackPool[sizeof(Pool)==0x24?1:-1];
#endif
