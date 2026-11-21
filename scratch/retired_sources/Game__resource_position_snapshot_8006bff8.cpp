#include "Game/resource_action_query_views.h"

extern "C" void fn_8006BFF8(ActionQuery* self, unsigned char)
{
    ActionVector& position =
        ((ActionOwner*)resolveAction(self->getResource()->handle))->model->position;
    ActionVector value(position.x, position.y, position.z);
    ((ActionOwner*)resolveAction(*self->getHandle()))->target = value;
}
