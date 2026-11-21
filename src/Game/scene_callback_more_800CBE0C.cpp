#include "Game/scene_callbacks_more.h"

extern "C" void fn_800CBE0C(SceneCallbacksMore::StateOwner*self){self->controller->flags&=~0x20000ULL;switch(fn_801F1224(0,3)){case 0:fn_8025795C(self->controller,1,0);break;case 1:fn_8025795C(self->controller,7,0);break;case 2:fn_8025795C(self->controller,8,0);break;case 3:fn_8025795C(self->controller,9,0);break;}}
