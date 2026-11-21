#ifndef GAME_INDEX_GRID_INIT_INTERNAL_H
#define GAME_INDEX_GRID_INIT_INTERNAL_H

#include "Game/bitset_internal.h"
struct InitGridArray {int count,capacity;void*data;};
struct InitGridInt3 {int x,y,z;InitGridInt3&operator=(const InitGridInt3&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct InitGridVec3 {float x,y,z;InitGridVec3&operator=(const InitGridVec3&v){x=v.x;y=v.y;z=v.z;return *this;}};
extern "C" {extern const InitGridInt3 game_int3_zero;extern const InitGridVec3 game_vec3_zero;}
struct InitGrid {InitGridArray first,second;int unknown18;BitSet_80207EE8 occupied;char unknown2C[0x40];InitGridInt3 cells;InitGridVec3 extent;int enabled;};

typedef char CheckInitGridArray[sizeof(InitGridArray)==12?1:-1];
typedef char CheckInitGridInt3[sizeof(InitGridInt3)==12?1:-1];
typedef char CheckInitGridVec3[sizeof(InitGridVec3)==12?1:-1];
typedef char CheckInitGrid[sizeof(InitGrid)==0x88?1:-1];
#endif
