#include "Game/early_motion_flags.h"

extern "C" int fn_800927C0(MotionFlagOwner*self,const MotionFlagInput*input){int result=fn_8009B868(self,input);if((input->flags&0x400000ULL)||self->overrideReady)self->ready=1;else self->ready=0;self->inputFlags=input->flags;return result;}
