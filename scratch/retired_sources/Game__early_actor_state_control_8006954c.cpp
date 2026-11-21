#include "Game/early_actor_state_control_views.h"
extern "C" signed char fn_8006954C(StateObject*self,short state,short value){StateActor*actor=resolveState(*self->getHandle());if(!fn_8006653C(self,0xD)&&(!fn_8006653C(self,0xC)||state==0xD||(fn_8006653C(self,0xC)&&self->mode==1))){actor->enabled=0;fn_80069654(self,state);actor->enabled=1;fn_8009FABC(actor,value);}return 1;}
