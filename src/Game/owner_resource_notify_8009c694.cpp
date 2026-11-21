#include "Game/owner_resource_callback_views.h"
extern "C" void fn_8009C694(OwnerCallbackAction* self)
{
    OwnerCallbackResource* resource=resolveOwnerCallback(self->agent->owner);
    fn_8025795C(resource,0xC,0);
}
