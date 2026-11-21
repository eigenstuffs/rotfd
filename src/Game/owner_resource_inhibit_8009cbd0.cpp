#include "Game/owner_resource_callback_views.h"
extern "C" void fn_8009CBD0(OwnerCallbackAction* self)
{
    OwnerCallbackResource* resource=resolveOwnerCallback(self->agent->owner);
    resource->flags |= 0x20000;
    fn_8025795C(resource,0xC,0);
}
