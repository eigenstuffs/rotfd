#ifndef GAME_ENGINE_CALLBACK_CLOCK_CTOR_H
#define GAME_ENGINE_CALLBACK_CLOCK_CTOR_H

#include "Game/engine_container_layer_ctor.h"
extern "C" {extern const char lbl_802ED000[],lbl_802ECEC0[];}
struct ClockResourceBase:ContainerBase_802563CC {ClockResourceBase(){vtable=lbl_802ED000;}~ClockResourceBase();};
struct ClockConstructBase:ClockResourceBase {ClockConstructBase(ClockResourceBase*owner){owner->vtable=lbl_802ECEC0;}~ClockConstructBase();};
struct CallbackClock_802ECEC0:ClockConstructBase {LayerHandleOne first;int index;LayerHandleTwo second;LayerHandleThree third;CallbackClock_802ECEC0();};

typedef char CallbackClockSizeCheck[(sizeof(CallbackClock_802ECEC0)==0x70)?1:-1];

#endif
