#include "Game/early_actor_record_dispatch_views.h"
extern "C"void fn_8003CE44(RecordDispatchOwner*self){lbl_801E9D24.service->remove(&self->handle);self->handle.tag=0;for(int i=0;i<self->count;++i)fn_80255678(resolveActor(self->handles[i]));fn_802073E8(self,0x1F,lbl_801E9D24.scene->state,lbl_803784C0);fn_8025D054(self);}
