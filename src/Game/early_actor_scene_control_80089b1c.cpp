#include "Game/early_actor_scene_control_views.h"
extern "C" void fn_80089B1C(SceneControlOwner* self) {
    if (self->first) { fn_80255678(self->first); self->first = 0; }
    if (self->second) { fn_80255678(self->second); self->second = 0; }
}
