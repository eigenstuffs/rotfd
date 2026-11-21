#ifndef GAME_CALLBACK_SNAPSHOT_INTERNAL_H
#define GAME_CALLBACK_SNAPSHOT_INTERNAL_H
#include "Game/callback_cycle_internal.h"
struct CallbackSnapshot {char unknown0[0x20];void *bytes;int size;};
extern "C" {
void *memcpy(void*,const void*,u32);
extern char lbl_801EF5C8[],lbl_802AECA0[],lbl_802AECB0[];
void *fn_801EFA1C(void*,int,const char*,const char*,int,int);
}
#endif
