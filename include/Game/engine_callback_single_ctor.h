#ifndef GAME_ENGINE_CALLBACK_SINGLE_CTOR_H
#define GAME_ENGINE_CALLBACK_SINGLE_CTOR_H

#include "Game/engine_container_layer_ctor.h"
extern "C" {extern const char lbl_802ECA18[],lbl_802EC798[],lbl_802ED000[];}
struct CallbackNativeResource:ContainerBase_802563CC {~CallbackNativeResource(){vtable=lbl_802ED000;}};
struct CallbackPair_802EC798:CallbackNativeResource {LayerHandleTwo first;LayerHandleThree second;int index;char unknown6C[4];CallbackPair_802EC798();~CallbackPair_802EC798(){vtable=lbl_802EC798;}};
struct CallbackSingleVtable {CallbackSingleVtable(CallbackPair_802EC798*owner){owner->vtable=lbl_802ECA18;}};
struct CallbackSingle_802ECA18:CallbackPair_802EC798,CallbackSingleVtable {LayerHandleThree handle70;CallbackSingle_802ECA18();};

typedef char CallbackSingleSizeCheck[(sizeof(CallbackSingle_802ECA18)==0x78)?1:-1];

#endif
