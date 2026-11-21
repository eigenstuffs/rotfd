#ifndef GAME_ENGINE_CALLBACK_FLAG_CTOR_H
#define GAME_ENGINE_CALLBACK_FLAG_CTOR_H

#include "Game/engine_container_layer_ctor.h"
extern "C" {extern const char lbl_802ECD68[];}
struct CallbackFlagVtable {CallbackFlagVtable(ContainerBase_802563CC*owner){owner->vtable=lbl_802ECD68;}};
struct CallbackFlag_802ECD68:ContainerBase_802563CC,CallbackFlagVtable {LayerHandleThree handle60;CallbackFlag_802ECD68();};

typedef char CallbackFlagSizeCheck[(sizeof(CallbackFlag_802ECD68)==0x68)?1:-1];

#endif
