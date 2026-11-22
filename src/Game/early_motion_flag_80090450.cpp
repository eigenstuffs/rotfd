#include "Game/early_motion_flags.h"

extern "C" void slot18__14CSpongeBobMoveFv(MotionFlagOwner*self){slot18__10CActorMoveFv(self);self->flags|=0x90000ULL;self->flags&=~0x80000000ULL;}
