#include "Game/owner_motion_timing_views.h"

extern "C" void slot198__14CWildSnailMoveFf(MotionTimingAgent*self,float delta)
{
    if(!self->hasFlag(0x8000000000ULL))slot18C__10CActorMoveFv(self);
    slot190__10CActorMoveFv(self);
    self->velocity=self->base+(self->movement/self->scale)*delta;
}
