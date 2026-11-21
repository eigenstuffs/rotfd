#include "Game/early_misc_event_control_views.h"
extern "C"void fn_800AB8C8(MiscDelayedOwner*self,float time){self->time+=time;if(self->time>lbl_80379090&&!self->complete){self->complete=1;fn_80072F98(self->controller->related->value);fn_802603A0(lbl_801E9D24.scene,0x9B,self->controller->related,lbl_80379094);}}
