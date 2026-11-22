#include "Game/early_resource_setup_views.h"
extern "C" void slot18__11CLevelAgentFv(SetupObject*self){assignSetup(self->resource,Handle_80021BCC(fn_801B52EC(lbl_801E9D24.manager,lbl_8029BA68)));fn_8005E66C(self->script);self->clearA(0,0);self->clearB(0,0);self->flags|=1ULL<<39;}
