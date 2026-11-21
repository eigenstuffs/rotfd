#include "Game/index_grid_init_internal.h"
extern "C" InitGrid*fn_80266758(InitGrid*self){self->first.count=0;self->first.capacity=0;self->first.data=0;self->second.count=0;self->second.capacity=0;self->second.data=0;__ct__15BitSet_80207EE8Fv(&self->occupied);self->cells=game_int3_zero;self->extent=game_vec3_zero;self->enabled=1;return self;}
