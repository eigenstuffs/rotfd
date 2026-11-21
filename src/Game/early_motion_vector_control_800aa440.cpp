#include "Game/early_motion_vector_control_views.h"
extern "C" void fn_800AA440(MotionVectorActor*self,const MotionVector&input){if(!(resolveResource(*self->slot37(0))->property&0x10000)){self->saved=input;self->acceleration+=input*self->scale;}}
