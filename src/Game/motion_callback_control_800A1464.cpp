#include "Game/motion_callback_controls.h"

extern "C" void fn_800A1464(CallbackAction*self,float delta){if(self->actor->value>=lbl_80378E44)fn_8007D6A0(self->actor->component,self->actor->previous);fn_800A4DF0(self,delta);}
