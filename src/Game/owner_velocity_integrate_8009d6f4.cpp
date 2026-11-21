#include "Game/owner_motion_timing_views.h"

extern "C" void fn_8009D6F4(MotionTimingAgent*self,float delta)
{
    if(!self->hasFlag(0x8000000000ULL))fn_8009B63C(self);
    fn_8009B674(self);
    self->velocity=self->base+(self->movement/self->scale)*delta;
}
