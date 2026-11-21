#ifndef GAME_PLATFORM_DISC_WAIT_INTERNAL_H
#define GAME_PLATFORM_DISC_WAIT_INTERNAL_H
#include "Game/platform_disc_read.h"
#include "Game/platform_disc_status.h"
typedef unsigned long u32;
struct Handle_801F7F10 {u32 value;Handle_801F7F10();~Handle_801F7F10();};
struct DiscWaitHandleFirst:Handle_801F7F10 {DiscWaitHandleFirst(){value=0;}~DiscWaitHandleFirst(){}};
struct DiscWaitHandle:DiscWaitHandleFirst {DiscWaitHandle(){value=0;}~DiscWaitHandle(){}};
struct DiscWaitGameStorage {char unknown00[0x278];};
struct DiscWaitGame:DiscWaitGameStorage {
 virtual void slot08();virtual void resize(int,int);virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();
 virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void setPicture(const Handle_801F7F10&);
};
struct DiscWaitGlobals {char unknown00[0x110];void*logger;DiscWaitGame*game;};
struct DiscWaitFileInfo {char unknown00[0x3C];};
extern "C" {
 extern DiscWaitGlobals lbl_801E9D24;
 extern const char lbl_802AF908[];
 extern char lbl_80373100[];
 extern signed char lbl_8037816C,lbl_8037816D,lbl_8037816E,lbl_80377F90;
 extern void(*lbl_80378164)(int);
 void fn_801EBB9C();void OSYieldThread();void fn_8028F4D8(void*,int,signed char);
 void fn_801FA014(void*,const char*,...);
 char*strcpy(char*,const char*);
 u32 DVDOpen(const char*,DiscWaitFileInfo*);
}
typedef char CheckDiscWaitGame[sizeof(DiscWaitGame)==0x27C?1:-1];
#endif
