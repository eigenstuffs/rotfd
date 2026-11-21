/* Actor offset completion/update; see docs/notes/game-early-actor-offset-finalize.md. */
#include "Game/early_actor_offset_finalize_views.h"
extern "C" void fn_800A10A4(OffsetOwner*self){self->actor->previousState=self->actor->state;self->actor->offset.add(lbl_80378E40,self->actor->height,lbl_80378E40);self->actor->position+=self->actor->offset+self->actor->position;self->actor->clearFlags(0x1000000000ULL);self->actor->clearFlags(0x8000000000ULL);fn_8009FABC(self->actor,22);fn_800A4E30(self);}
