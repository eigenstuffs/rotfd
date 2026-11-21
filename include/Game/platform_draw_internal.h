#ifndef GAME_PLATFORM_DRAW_INTERNAL_H
#define GAME_PLATFORM_DRAW_INTERNAL_H
#include "objects_owner_internal.h"
struct PlatformDrawOwner;struct PlatformDrawOutput;
struct PlatformDrawOwner : BaseObject_Z {
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
 virtual void draw(PlatformDrawOutput*,void*,void*,void*);
 char unknown0C[0x68];
 u32 count74;char unknown78[4];u32 value7C;char unknown80[0x14];u32 value94;char unknown98[0x24];char stateBC[4];
};
struct PlatformDrawOutput {char unknown00[0xBD8];u32 valueBD8,valueBDC;};
extern "C" {void fn_800F22F4(void*,u32);void GXDrawDone();}
struct PlatformIndexBlockStorage {signed char flag00;char unknown01[0x3F];};
struct PlatformIndexBlock_8028310C : PlatformIndexBlockStorage {
 ~PlatformIndexBlock_8028310C();
 virtual void reset();
 virtual void hook();
 static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
typedef char CheckPlatformDrawOwner[sizeof(PlatformDrawOwner)==0xC0?1:-1];
typedef char CheckPlatformDrawOutput[sizeof(PlatformDrawOutput)==0xBE0?1:-1];
typedef char CheckPlatformIndexBlock[sizeof(PlatformIndexBlock_8028310C)==0x44?1:-1];
#endif
