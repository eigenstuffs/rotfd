#include "Game/owner_target_action_views.h"
extern "C" void slot1A0__11CScriptMoveFv(TargetActionAgent*self){if(!(resolveTargetAction(*self->getHandle(0))->flags&0x10000)){TargetActionResource*target=self->currentTarget();if(target)fn_8009F754(self,target);}}
