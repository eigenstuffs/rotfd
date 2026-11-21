#include "Game/early_controller_dispatch_views.h"
extern "C" void fn_8006311C(EarlyDispatchResource*self){fn_8005E670(self->script);fn_8002B820(self);if(self->registered==1){resolveEarlyDispatch(self->resource)->slot11();fn_802139D8(resolveEarlyDispatch(self->resource));self->flags&=~0x8000ULL;if(fn_8009FD38(resolveEarlyDispatch(*self->getControllerHandle()))==1)fn_80069218(self->script,3);}}
