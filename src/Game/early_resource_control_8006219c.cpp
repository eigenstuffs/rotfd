#include "Game/early_resource_control_views.h"
extern "C" void slot30__11CLevelAgentFv(ControlObject*self){if((self->flags & (1ULL<<17))==0){signed char valid=validControl(Handle_80021B54(self->resource));if(valid)fn_802139D8(resolveControl(Handle_80021B54(self->resource)));}}
