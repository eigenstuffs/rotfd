#include "Game/early_actor_state_control_views.h"
extern "C" void fn_80069398(StateObject*self,float speed){StateActor*actor=resolveState(*self->getHandle());actor->speed=speed;actor->speedCopy=speed;if(lbl_803787D4==speed)actor->flags&=~0x400ULL;else actor->flags|=0x400ULL;}
