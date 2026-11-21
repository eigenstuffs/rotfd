#include "Game/motion_controller_event_views.h"

extern "C" void fn_800A37D0(ControllerAction*self){ControllerMonitor*m=fn_8005EE10(resolveController(self->actor->handle));if(m->first)fn_8006803C(m,self->actor->key);self->actor->value=lbl_80378E60;}
