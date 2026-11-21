#ifndef GAME_PLATFORM_INDEX_LISTS_INTERNAL_H
#define GAME_PLATFORM_INDEX_LISTS_INTERNAL_H
#include "Game/platform_arrays_internal.h"
// Native six-byte aggregate returned in r3 and the upper half of r4.
inline PlatformLink* platformLink(PlatformArrays_802EA884*self,int i){return self->indices.data+i;}
extern "C" {
PlatformIndexList fn_801ECA54(PlatformArrays_802EA884*,short,short);
PlatformIndexList fn_8026EBE8(PlatformArrays_802EA884*,const PlatformIndexList&,const PlatformIndexList&);
}
typedef char CheckPlatformIndexList[sizeof(PlatformIndexList)==6?1:-1];
#endif
