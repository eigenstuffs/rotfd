#include "Game/early_actor_position_state_control_views.h"
extern "C"void fn_8005C128(PositionStateActor*self,int value){fn_8002B824(self,value);self->slot41(0,0);float y=resolveActor(*resolveActor(self->actor)->slot37(0))->transform->position.y;resolveActor(self->actor)->savedY=y;fn_8005C264(self,value);}
