#include "Game/owner_motion_query_views.h"
inline float upperLimit(MotionQueryAgent* a) { return a->limit394; }
extern "C" void fn_800965BC(MotionQueryAction* self, float delta)
{
    float first, second;
    MotionQueryVector vector;
    fn_80099F74(self->agent, &first);
    fn_8009A270(self->agent, &second);
    if (first > upperLimit(self->agent) || second > self->agent->limit3D8)
        fn_8007D6A0(&self->agent->controls, 8);
    else {
        fn_8009A3CC(self->agent, &vector);
        self->agent->apply(&vector, delta);
    }
}
