#include "Game/owner_target_action_views.h"
extern "C" void fn_8009F834(TargetActionAgent*self){if(!(resolveTargetAction(*self->getHandle(0))->flags&0x10000)){TargetActionResource*target=self->currentTarget();if(target)fn_8009F754(self,target);}}
