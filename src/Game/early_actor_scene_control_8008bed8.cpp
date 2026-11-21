#include "Game/early_actor_scene_control_views.h"
extern "C" void fn_8008BED8(SceneControlOwner* self) {
    void* target = fn_80056A0C(lbl_801E9D24.scene->mode);
    if (!target) {
        fn_802073E8(self->controller, 0x7D, self->controller, lbl_80378AE0);
    } else {
        self->actor->target = target;
        fn_80257828(self->controller, 0x20, 0x7D, 0);
        fn_802073E8(self->controller, 0xA8, target, lbl_80378AE0);
        if (lbl_803776B8 && lbl_803776B8->first)
            fn_8006803C(lbl_803776B8, self->actor->record);
    }
}
