#include "Game/owner_motion_gate_views.h"
inline float lowerGateLimit(MotionGateAgent* agent){return agent->limit3DC;}
extern "C" void fn_80097724(MotionGateAction* self,float delta)
{
    float distance;
    MotionGateVector vector;
    fn_8009A270(self->agent,&distance);
    fn_8009A6D4(self->agent,&vector);
    if(distance<lowerGateLimit(self->agent))fn_8007D6A0(&self->agent->controls,5);
    else self->agent->apply(&vector,delta);
}
