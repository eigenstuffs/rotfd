#include "Game/actor_three_vector_reset_800966D8.h"

extern "C" void fn_800966D8(ActorResetAction* self)
{
    self->target0C->flags38 |= 0x20000ULL;
    self->agent08->setVelocity(game_vec3_zero);
    self->agent08->setAngularVelocity(game_vec3_zero);
    self->agent08->setMovement(game_vec3_zero);
    fn_8007D7F4(&self->agent08->controls318, 0);
    fn_8007D7F4(&self->agent08->controls318, 1);
    fn_8007D7F4(&self->agent08->controls318, 2);
}
