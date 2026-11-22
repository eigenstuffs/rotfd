#include "Game/early_motion_flags.h"

extern "C" int slot5C__14CSpongeBobMoveFv(MotionFlagOwner*self,const MotionFlagInput*input){int result=slot5C__10CActorMoveFv(self,input);if((input->flags&0x400000ULL)||self->overrideReady)self->ready=1;else self->ready=0;self->inputFlags=input->flags;return result;}
