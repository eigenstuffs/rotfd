#ifndef GAME_EARLY_ACTOR_PHASE_CONTROL_VIEWS_H
#define GAME_EARLY_ACTOR_PHASE_CONTROL_VIEWS_H

struct PhaseRecord{char unknown00[8];int key;};
struct PhaseActor{char unknown00[0x318];PhaseRecord record;char unknown324[0xE1];signed char enabled405,enabled406;};
struct PhaseOwner{char unknown00[8];PhaseActor*actor;void*controller;char unknown10[0x30];float timer;};
struct PhaseMonitor{char unknown00[0x130];void*first;};
extern "C"{extern PhaseMonitor*lbl_803776B8;void fn_8025795C(void*,int,int);void fn_8006803C(PhaseMonitor*,int);void fn_80092BF4(PhaseActor*,int,double);void fn_80092DAC(PhaseActor*,double);int fn_80092844(PhaseActor*);void fn_8007D6A0(PhaseRecord*,int);signed char fn_8007D604(PhaseRecord*,int);}

#endif
