#ifndef GAME_PLATFORM_ARAM_INTERNAL_H
#define GAME_PLATFORM_ARAM_INTERNAL_H
#include "Game/platform_aram_lifetime_internal.h"
// Offset names reflect the observed two independent ARAM cursors.
struct PlatformAramOwner { unsigned long cursor00, cursor04; void* unknown08; };
// Native ARQ request occupies 32 bytes; the game's occupied flag follows it.
struct PlatformAramRequest {
    PlatformAramRequest* next;
    unsigned long owner, type, priority, source, dest, length;
    void (*callback)(unsigned long);
};
struct PlatformAramSlot { PlatformAramRequest request; int occupied; };
typedef PlatformAramPool PlatformAramBytePool;
extern "C" {
void fn_8028531C();
void fn_8028581C(PlatformAramOwner*);
unsigned long fn_80285730(PlatformAramOwner*);
int fn_80285458(PlatformAramBytePool*,unsigned char);
void fn_8028533C(void*,unsigned long,unsigned long,unsigned long,signed char);
void fn_80285A6C(unsigned long);
extern PlatformAramBytePool lbl_8035DE34;
unsigned long fn_80285784(PlatformAramOwner*,unsigned long);
unsigned long fn_80285800(PlatformAramOwner*,unsigned long);
extern PlatformAramSlot lbl_8035D528[64],lbl_8035DE58[64];
}
typedef char CheckAramBytePool[sizeof(PlatformAramBytePool)==36?1:-1];
typedef char CheckAramRequest[sizeof(PlatformAramRequest)==32?1:-1];
typedef char CheckAramSlot[sizeof(PlatformAramSlot)==36?1:-1];
#endif
