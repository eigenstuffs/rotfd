#include "Game/motion_controller_event_views.h"

extern "C" void fn_800A386C(ControllerAction*self){ControllerMonitor*m=fn_8005EE10(resolveController(self->actor->handle));if(m->second)fn_80068158(m,self->actor->key);}
