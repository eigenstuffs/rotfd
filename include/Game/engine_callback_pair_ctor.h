#ifndef GAME_ENGINE_CALLBACK_PAIR_CTOR_H
#define GAME_ENGINE_CALLBACK_PAIR_CTOR_H

#include "Game/engine_container_layer_ctor.h"
extern "C" {extern const char lbl_802ED000[],lbl_802EC798[];}
struct CallbackBase_802ED000:ContainerBase_802563CC {CallbackBase_802ED000(){vtable=lbl_802ED000;}~CallbackBase_802ED000();};
struct CallbackPairBase:CallbackBase_802ED000 {CallbackPairBase(CallbackBase_802ED000*owner){owner->vtable=lbl_802EC798;}~CallbackPairBase();};
struct CallbackPair_802EC798:CallbackPairBase {LayerHandleTwo first;LayerHandleThree second;int index;CallbackPair_802EC798();};

typedef char CallbackPairSizeCheck[(sizeof(CallbackPair_802EC798)==0x70)?1:-1];

#endif
