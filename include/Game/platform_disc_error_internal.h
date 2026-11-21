#ifndef GAME_PLATFORM_DISC_ERROR_INTERNAL_H
#define GAME_PLATFORM_DISC_ERROR_INTERNAL_H
#include "Game/platform_disc_wait_internal.h"
struct DiscErrorInputStorage {char unknown00[0x1C];};
struct DiscErrorInput:DiscErrorInputStorage {
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();
 virtual void update(float);virtual signed char query(int);
};
struct DiscErrorGlobals {char unknown00[0x110];void*logger;char unknown114[0x40];DiscErrorInput*input;};
extern "C" {
 extern const char lbl_802AFB30[],lbl_802AFB40[];
 extern const float lbl_8037B98C;
 extern void(*lbl_80378160)(int);
 void VISetBlack(int);void VIFlush();void VIWaitForRetrace();void fn_8028EA98(int);
 u32 OSGetTick();void GXDrawDone();void GXAbortFrame();void LCDisable();void OSResetSystem(int,u32,int);
}
typedef char CheckDiscErrorInput[sizeof(DiscErrorInput)==0x20?1:-1];
typedef char CheckDiscErrorGlobals[sizeof(DiscErrorGlobals)==0x158?1:-1];
#endif
