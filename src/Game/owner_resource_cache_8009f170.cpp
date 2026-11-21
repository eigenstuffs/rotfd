#include "Game/owner_resource_action_views.h"
extern "C" ResourceActionResource*fn_8009F170(ResourceActionAgent*self){
if(self->cached==(ResourceActionResource*)-1){self->cached=resolveResourceAction(fn_8005E9A0()->owner);self->cachedActive=1;}
if(self->cached){if(self->cachedActive)self->cached=resolveResourceAction(fn_8005E9A0()->owner);}else self->cachedActive=0;
return self->cached;}
