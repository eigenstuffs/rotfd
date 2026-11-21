#ifndef GAME_ENGINE_OWNER_WRAPPERS_H
#define GAME_ENGINE_OWNER_WRAPPERS_H

#include "Game/engine_bitset_find.h"
typedef struct EngineOwnerWrapperFlags{char unknown00[0x30];unsigned long long flags;}EngineOwnerWrapperFlags;
typedef struct EngineOwnerWrapperReset{char unknown00[0x20];unsigned long word20;}EngineOwnerWrapperReset;
typedef struct EngineOwnerWrapperFind{char unknown00[0x18c];EngineBitsetFind bits;int count;}EngineOwnerWrapperFind;
typedef struct EngineOwnerWrapperRecords{char unknown00[0x188];char* records;}EngineOwnerWrapperRecords;
typedef struct EngineOwnerWrapperValues{char unknown00[0x170];float a,b,c,d;}EngineOwnerWrapperValues;
#ifdef __cplusplus
extern "C"{
#endif
extern const float lbl_8037B140,lbl_8037B154,lbl_8037B160,lbl_8037B164;
void fn_8021FC00(void*,int);
void fn_80220754(EngineOwnerWrapperFlags*);
void slot18__11Activable_ZFv(EngineOwnerWrapperReset*);
void fn_80213920(EngineOwnerWrapperReset*,int);
void fn_80224888(EngineOwnerWrapperFlags*);
void fn_80224A10(EngineOwnerWrapperFlags*);
void fn_80227A14(EngineOwnerWrapperFlags*);
void fn_80230978(EngineOwnerWrapperFlags*);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
struct EngineOwnerWrapperRecord{char unknown00[0x1c];void* link;unsigned long long flags;};
struct EngineOwnerWrapperStorage{char unknown00[8];};
struct EngineOwnerWrapperVirtual:EngineOwnerWrapperStorage{
virtual void slot08();
virtual void slot0C();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1C();
virtual void slot20();
virtual void slot24();
virtual void slot28();
virtual void slot2C();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual void slot3C();
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4C();
virtual void slot50();
virtual void slot54();
virtual void slot58();
virtual void slot5C();
virtual void slot60();
virtual void slot64(void*,const EngineOwnerWrapperRecord*,unsigned long long,int);
};
extern "C" signed char fn_8021E8B8(EngineOwnerWrapperVirtual*,const EngineOwnerWrapperRecord*,int,int);
#endif

#ifdef __cplusplus
extern "C"{
#endif
int fn_80224B34(EngineOwnerWrapperFind*,int);
void fn_80227F4C(EngineOwnerWrapperValues*,int);
void fn_8022A160(EngineOwnerWrapperFlags*);
void fn_8022D1D8(EngineOwnerWrapperReset*);
void fn_8022D218(EngineOwnerWrapperFlags*);
void fn_8022D264(EngineOwnerWrapperFlags*);
void fn_80230700(EngineOwnerWrapperFlags*);
#ifdef __cplusplus
}
#endif
#endif
