#include "Game/owner_motion_query_views.h"
inline float lowerVariantLimit(MotionQueryAgent* a) { return a->limit3DC; }
extern "C" void fn_800982BC(MotionQueryAction* self, float delta)
{
    float distance;
    MotionQueryVector vector;
    fn_8009A270(self->agent, &distance);
    fn_8009A6D4(self->agent, &vector);
    self->agent->apply(&vector, delta);
    if (distance < lowerVariantLimit(self->agent))
        fn_8007D6A0(&self->agent->controls, 5);
}
