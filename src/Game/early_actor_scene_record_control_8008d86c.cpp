#include "Game/early_actor_scene_record_control_views.h"
extern "C" void fn_8008D86C(SceneRecordOwner* self) {
    switch(fn_801F1224(0,4)) {
    case 0: fn_80257828(self->controller,7,0x8D,0); break;
    case 1: fn_80257828(self->controller,8,0x8D,0); break;
    case 2: fn_80257828(self->controller,9,0x8D,0); break;
    case 3: fn_80257828(self->controller,10,0x8D,0); break;
    case 4: fn_80257828(self->controller,11,0x8D,0); break;
    }
}
