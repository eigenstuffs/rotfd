#include "Game/motion_callback_controls.h"

extern "C" void fn_800A1360(CallbackAction*self,float delta){if(self->actor->hasFlag(0x8000000000ULL))fn_8007D6A0(self->actor->component,self->actor->previous);else fn_800A4DF0(self,delta);}
