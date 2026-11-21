#include "Game/handle_array_clear_internal.h"
extern "C" void fn_80269FE0(ArrayClearView*self){self->handles.resize(0);fn_8023EFAC(resolved(self->owner),&self->handles);}
