#include "Game/early_misc_event_control_views.h"
extern "C"void fn_8006A810(void*,MiscObject*dest,MiscObject*source){MiscVector v(source->transform->position.x,source->transform->position.y,source->transform->position.z);v.y=dest->transform->position.y;fn_8023D100(dest,&v);fn_8023DE28(dest);}
