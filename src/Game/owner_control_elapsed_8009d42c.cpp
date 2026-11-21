#include "Game/owner_motion_timing_views.h"
extern "C" void fn_8009D42C(MotionTimingAgent*self,float delta)
{
    fn_8009ACBC(self,delta);
    self->elapsed += delta;
    if(self->elapsed>=lbl_80378DC8 && (fn_8007D604(&self->controls,1)||fn_8007D604(&self->controls,0))) {
        self->elapsed=lbl_80378DA8;
        if(fn_801F1224(0,1)) {
            fn_8009D820(self);
            fn_8007D6A0(&self->controls,1);
        }else fn_8007D6A0(&self->controls,0);
    }
}
