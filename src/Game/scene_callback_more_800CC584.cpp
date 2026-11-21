#include "Game/scene_callbacks_more.h"

extern "C" void fn_800CC584(SceneCallbacksMore::StateOwner*self,float delta){if(self->actor->hasFlag(0x20000000000ULL))fn_800CCCEC(self->actor);SceneCallbacksMore::Vector value;value.x=self->actor->vector.x;value.y=self->actor->vector.y;value.z=self->actor->vector.z;self->actor->slot101(&value,delta);}
