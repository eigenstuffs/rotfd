#include "Game/owner_motion_query_views.h"
inline bool belowHeight(MotionQueryAgent* agent) { return agent->position(0).y <= agent->height3C8; }
extern "C" void fn_80095C40(MotionQueryAction* self, float)
{
    self->agent->position(0);
    if (fn_8025E9FC(self->target, 0x39) || belowHeight(self->agent))
        fn_8007D6A0(&self->agent->controls, 5);
    self->agent->finish();
}
