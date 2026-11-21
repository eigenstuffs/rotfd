#include "Game/early_actor_token_control_views.h"
extern "C"void fn_800AEFE8(TokenControlOwner*self){self->actor->flags|=0x600ULL;resolveToken(self->actor->related(0))->relatedFlags|=0x40000;}
