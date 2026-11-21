#ifndef GAME_ENGINE_MANIPULATOR_DESTROY_H
#define GAME_ENGINE_MANIPULATOR_DESTROY_H

#include "Game/engine_group_membership.h"
struct ManipulatorDestroyWrapped {Handle_801F7F10 handle;};
struct ManipulatorDestroyArray {int count,capacity;ManipulatorDestroyWrapped*data;};
struct ManipulatorDestroyObject {
 unsigned long key;Handle_801F7F10 handle;void*table;char unknown0C[12];signed char active;char unknown19[7];
 float parameters20[6];ManipulatorDestroyArray records;ManipulatorDestroyWrapped handle44,handle48;int group;ManipulatorDestroyWrapped handle50;char handles54[12];ManipulatorDestroyWrapped handle60;
 inline signed char isActive()const{return active;}
};

typedef char ManipulatorDestroyObjectSizeCheck[(sizeof(ManipulatorDestroyObject)==0x64)?1:-1];
extern "C" ManipulatorDestroyObject*fn_80211508(ManipulatorDestroyObject*,short);

#endif
