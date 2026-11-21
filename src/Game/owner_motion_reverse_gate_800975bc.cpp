#include "Game/owner_motion_gate_views.h"
inline float upperGateLimit(MotionGateAgent* agent){return agent->limit394;}
inline float secondGateLimit(MotionGateAgent* agent){return agent->limit3D8;}
extern "C" void fn_800975BC(MotionGateAction* self,float delta)
{
    float first,second;
    MotionGateVector vector;
    fn_80099F74(self->agent,&first);
    if(first>upperGateLimit(self->agent))fn_8007D6A0(&self->agent->controls,5);
    else {
        fn_8009A270(self->agent,&second);
        if(second>secondGateLimit(self->agent))fn_8007D6A0(&self->agent->controls,8);
        else {
            fn_8009A3CC(self->agent,&vector);
            vector=-vector;
            self->agent->apply(&vector,delta);
        }
    }
}
