#ifndef GAME_ENGINE_BASIS_RESOURCE_CTOR_H
#define GAME_ENGINE_BASIS_RESOURCE_CTOR_H

struct RootStorage_80207414 {unsigned long unknown00,identity;};
struct BaseObject_Z:RootStorage_80207414 {BaseObject_Z();virtual ~BaseObject_Z();virtual void slot0C(unsigned long);virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();};
struct Resource_802E9E20:BaseObject_Z {Resource_802E9E20(){}virtual ~Resource_802E9E20();};
struct Handle_801F7F10 {unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
struct BasisZeroHandle:Handle_801F7F10 {BasisZeroHandle(){value=0;}};
struct Handle_8003F47C:BasisZeroHandle {Handle_8003F47C();~Handle_8003F47C();};
extern "C" {void*memset(void*,int,unsigned long);extern const float lbl_8037B2FC,lbl_8037B2F8;}
struct BasisResource_802EBFD8:Resource_802E9E20 {
 float position[3],rotation[4];char unknown28[4];float basis[9];char unknown50[0x14];int type,field68,field6C;signed char field70;char unknown71[3];Handle_8003F47C handles[2];
 BasisResource_802EBFD8();virtual ~BasisResource_802EBFD8();virtual void slot20();virtual void slot24();
};

typedef char BasisResourceSizeCheck[(sizeof(BasisResource_802EBFD8)==0x7C)?1:-1];

#endif
