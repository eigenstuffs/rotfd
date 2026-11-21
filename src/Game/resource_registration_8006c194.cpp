#include "Game/resource_action_query_views.h"

extern "C" signed char fn_8006C194(ActionQuery* self, signed char)
{
    if (lbl_803776B8->getResource()->registration == 0)
        lbl_803776B8->ensureRegistration();
    ActionResource* resource = self->getResource();
    fn_80024A5C(lbl_803776B8->getResource()->registration, resource);
    return 1;
}
