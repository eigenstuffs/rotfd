#include "Game/early_actor_reflection_control_views.h"
extern "C"void fn_80083BDC(ReflectionControlOwner*self){self->actor->enabled40C=0;self->actor->flags&=~0x80000000ULL;if(lbl_803776B8&&lbl_803776B8->second)fn_80068158(lbl_803776B8,self->actor->record);}
