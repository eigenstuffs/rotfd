#include "Game/early_resource_setup_views.h"
extern "C" void fn_80061F0C(SetupObject*self,const Handle_801F7F10&input){
fn_802001D4(resolveSetup(input),Handle_80021B54(self->resource),0);
resolveSetup(Handle_80021B54(self->resource))->ownerBind(self->owner);
clearSetupFlags(Handle_80021B54(self->resource));
self->flags|=1ULL<<17;self->slot11();
SetupCallback*callback=(SetupCallback*)fn_801EFA1C(lbl_801EF5C8,0x8C,lbl_8029BA74,lbl_8029BA84,0x83,4);
if(callback){initializeSetupCallback(callback);}
self->callback=callback;
}
