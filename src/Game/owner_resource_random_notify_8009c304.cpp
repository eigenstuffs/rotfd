#include "Game/owner_motion_timing_views.h"
extern "C" void fn_8009C304(MotionTimingAction*self)
{
    MotionTimingResource* resource=resolveMotionTiming(self->agent->owner);
    resource->flags &= ~0x20000;
    switch(fn_801F1224(0,2)) {
    case 0:fn_8025795C(resource,1,0);break;
    case 1:fn_8025795C(resource,7,0);break;
    case 2:fn_8025795C(resource,8,0);break;
    }
}
