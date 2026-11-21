#include "Game/early_actor_transition_control_views.h"
extern "C" void fn_800BEC04(void*){TransitionControlWindow*window=lbl_801E9D24.window;if(window){signed char active=window->getActive();if(!active){active=1;window->begin();}lbl_801E9D24.scene->service->apply(window);fn_801EBB9C(window->getOutput());if(active)window->end();}}
