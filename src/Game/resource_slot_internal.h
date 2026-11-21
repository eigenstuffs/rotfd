#ifndef GAME_RESOURCE_SLOT_INTERNAL_H
#define GAME_RESOURCE_SLOT_INTERNAL_H
#include "world_curve_arrays_internal.h"
struct ResetHandle2 : OwnerHandle {ResetHandle2(){value=0;}~ResetHandle2(){}};
struct ResetHandle3 : ResetHandle2 {ResetHandle3(){value=0;}~ResetHandle3(){}};
struct ResetCopy1 : OwnerHandle {
    ResetCopy1(const OwnerHandle&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
    ~ResetCopy1(){}
};
struct ResetTarget;
extern "C" void fn_80240120(ResetTarget*,int);
extern "C" void fn_8023D648(ResetTarget*);
struct ResetTarget {
    char prefix[0x10];OwnerHandle handle10;u32 field14,field18;
    OwnerHandle handle1C,handle20,handle24,handle28;
    char unknown2C[0x104];OwnerHandle handle130;
    void set10(const OwnerHandle&h){handle10=h;}
    void set24(const OwnerHandle&h){handle24=h;}
    void set28(const OwnerHandle&h){handle28=h;}
    void set1C(const OwnerHandle&h){handle1C=h;fn_8023D648(this);}
    void set20(const OwnerHandle&h){handle20=h;fn_8023D648(this);}
    void set130(const OwnerHandle&h){handle130=ResetCopy1(h);}
};
struct ResetBitset {int count,capacity;u32* words;int bits;};
struct ResetManager {char unknown00[0x2C];OwnerHandle* entries;ResetBitset occupied;};
extern "C" int fn_80207B94(void*,int,int);
static inline ResetTarget* target(const OwnerHandle& h){return (ResetTarget*)h.get();}
static inline bool different(const OwnerHandle&a,const OwnerHandle&b){Activable_Z* p=b.get();return p!=a.get();}

#endif
