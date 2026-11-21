#ifndef GAME_ENGINE_CONTAINER_LAYER_CTOR_H
#define GAME_ENGINE_CONTAINER_LAYER_CTOR_H

typedef unsigned long u32;
extern "C" {extern const char lbl_802EC6A0[];}
struct Handle_801F7F10 {u32 value;Handle_801F7F10();~Handle_801F7F10();};
struct LayerHandleOne:Handle_801F7F10 {LayerHandleOne(){value=0;}};
struct LayerHandleTwo:LayerHandleOne {LayerHandleTwo(){value=0;}};
struct LayerHandleThree:LayerHandleTwo {LayerHandleThree(){value=0;}};
struct ContainerBase_802563CC {u32 unknown00[2];const void*vtable;char unknown0C[0x2C];unsigned long long flags;char unknown40[0x20];ContainerBase_802563CC();~ContainerBase_802563CC();};
struct LayerCtorWord {u32 value;LayerCtorWord(ContainerBase_802563CC*owner){owner->vtable=lbl_802EC6A0;value=0;}};
struct ContainerLayer_802EC6A0:ContainerBase_802563CC {LayerCtorWord word60;LayerHandleThree handle64;u32 word68,word6C;ContainerLayer_802EC6A0();};

typedef char ContainerLayerSizeCheck[(sizeof(ContainerLayer_802EC6A0)==0x70)?1:-1];

#endif
