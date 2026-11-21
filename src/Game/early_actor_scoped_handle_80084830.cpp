#include "Game/early_actor_scoped_handle_views.h"
inline const Handle_801F7F10*getScopedPointer(ScopedControllerObject*o){return &o->node->handle;}
inline const Handle_801F7F10&asScoped(const Handle_801F7F10&h){return h;}
extern "C" void fn_80084830(ScopedOwner*self,double delta){if(self->actor->enabled40C)fn_8007D6A0(&self->actor->record,fn_80092844(self->actor));if(fn_8025E9FC(self->controller,0x98)){Handle_801F7F10 h(asScoped(Handle_801F7F10(*getScopedPointer(fn_8025E50C(self->controller)))));fn_80224038(self->actor,&resolveScoped(h)->handle);fn_8007D6A0(&self->actor->record,0x16);}fn_80092DAC(self->actor,delta);}
