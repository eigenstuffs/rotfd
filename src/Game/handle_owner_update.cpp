#include "Game/handle_array_clear_internal.h"
extern "C" {void fn_80268364(ArrayClearView*,float);void fn_8028DD18(ArrayClearView*);void fn_8023DE28(Object*);}
extern "C" void fn_8026A690(ArrayClearView*self,float step){fn_80268364(self,step);fn_8028DD18(self);fn_8023DE28(resolved(self->owner));}
