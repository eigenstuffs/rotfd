#ifndef GAME_ENGINE_CALLBACK_VARIANT_CTORS_H
#define GAME_ENGINE_CALLBACK_VARIANT_CTORS_H
#include "Game/engine_callback_control_ctor.h"
extern "C" {extern const char lbl_802EC8A8[],lbl_802EC958[],lbl_802ECAF8[];}
struct LodAgent_802EC8A8:CallbackControl_802ECC00 {LodAgent_802EC8A8();};
struct LodDynamicAgent_802EC958:CallbackPair_802EC798 {LodDynamicAgent_802EC958();};
struct SkinAgent_802ECAF8:CallbackPair_802EC798 {SkinAgent_802ECAF8();};
typedef char LodAgentSizeCheck[(sizeof(LodAgent_802EC8A8)==0x80)?1:-1];
typedef char LodDynamicAgentSizeCheck[(sizeof(LodDynamicAgent_802EC958)==0x70)?1:-1];
typedef char SkinAgentSizeCheck[(sizeof(SkinAgent_802ECAF8)==0x70)?1:-1];
#endif
