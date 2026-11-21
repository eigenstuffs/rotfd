#include "Game/early_spatial_state_copy_views.h"
extern "C"void fn_8002AF3C(ResetSpatialOwner*self){fn_8025A0A4(self);const ResetSpatialVector&position=resolveActor(*resolveActor(self->actor)->slot37(0))->transform->position;resolveActor(self->actor)->setPosition(ResetSpatialVector(position.x,position.y,position.z));resolveResource(self->resource)->property&=~0x40000UL;}
