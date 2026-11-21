#include "Game/motion_callback_controls.h"

extern "C" void fn_800A1404(CallbackAction*self){self->actor->previous=self->actor->selector;fn_8009FABC(self->actor,0x3E);fn_8009FB80(self->actor,0x41);fn_8009FB80(self->actor,0x42);fn_800A4E30(self);}
