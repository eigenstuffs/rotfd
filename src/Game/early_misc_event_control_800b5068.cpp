#include "Game/early_misc_event_control_views.h"
extern "C"void fn_800B5068(MiscTimerOwner*self,float time){fn_800B4628(self,time);if(self->enabled){self->time-=time;if(self->time<lbl_80379350)fn_800B5134(self,0);}}
