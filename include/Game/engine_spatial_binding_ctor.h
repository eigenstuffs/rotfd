#ifndef GAME_ENGINE_SPATIAL_BINDING_CTOR_H
#define GAME_ENGINE_SPATIAL_BINDING_CTOR_H

#include "Game/engine_spatial_handle_ctor.h"

extern "C" const float lbl_8037B428;
struct SpatialBinding_802EC2C0:SpatialBase_802EC118 {
 SpatialFields fields;SpatialTwiceZeroHandle handle;
 int field30,field34,field38,field3C,field40,field44,field48,field4C,field50,field54,field58,field5C,field60,field64,field68,field6C,field70,field74,field78;
 SpatialBinding_802EC2C0();virtual ~SpatialBinding_802EC2C0();virtual void slot4C();
};

typedef char SpatialBindingSizeCheck[(sizeof(SpatialBinding_802EC2C0)==0x7C)?1:-1];

#endif
