#include "Game/early_selection_event_control_views.h"
extern "C"void fn_800371C4(SelectionOwner*self){SelectionVector motion(lbl_80378420,lbl_80378454,lbl_80378420);resolveActor(self->actor)->setMotion(motion);resolveActor(self->actor)->state=0;fn_8025795C(self,1,0);fn_800356DC(self);}
