#include "Game/engine_owner_small.h"

void fn_8020CE5C(struct EngineOwnerSmallReset* self)
{
    slot18__11Activable_ZFv(self);
    self->handle20 = 0;
    self->handle24 = 0;
    self->position.x = game_vec2_zero.x;
    self->position.y = game_vec2_zero.y;
}
