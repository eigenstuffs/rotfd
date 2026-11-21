#include "Game/early_action_control_views.h"

extern "C" void fn_80095BF8(ActionOwner* self){self->controller->flags|=0x20000ULL;self->controller->slot11();}
