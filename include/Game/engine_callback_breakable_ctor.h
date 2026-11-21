#ifndef GAME_ENGINE_CALLBACK_BREAKABLE_CTOR_H
#define GAME_ENGINE_CALLBACK_BREAKABLE_CTOR_H

#include "Game/engine_callback_control_ctor.h"
extern "C" {extern const char lbl_802EC810[];}
struct BreakableHandleFour:LayerHandleThree {BreakableHandleFour(){value=0;}};
struct BreakableHandleFive:BreakableHandleFour {BreakableHandleFive(){value=0;}};
struct BreakableHandleSix:BreakableHandleFive {BreakableHandleSix(){value=0;}};
struct BreakableVtable {BreakableVtable(CallbackControl_802ECC00*owner){owner->vtable=lbl_802EC810;}};
struct Breakable_802EC810:CallbackControl_802ECC00,BreakableVtable {BreakableHandleSix handle80;Breakable_802EC810();};

typedef char BreakableSizeCheck[(sizeof(Breakable_802EC810)==0x88)?1:-1];

#endif
