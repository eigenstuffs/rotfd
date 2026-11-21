/* Retained native handle controls; see docs/notes/game-early-resource-controls.md. */
#include "Game/early_resource_control_views.h"
extern "C" void fn_800622CC(ControlObject*self){if((self->flags & (1ULL<<18))==0){signed char valid=validControl(Handle_80021B54(self->resource));if(valid)fn_80213A18(resolveControl(Handle_80021B54(self->resource)));}}
