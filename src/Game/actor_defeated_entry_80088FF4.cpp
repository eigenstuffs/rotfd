#include "Game/early_actor_scene_control_views.h"
extern "C" void fn_80088FF4(SceneControlOwner* self) {
    lbl_801E9D24.system->active = 0;
    fn_80057E40(lbl_801E9D24.scene->mode);
    SceneControlMode* mode = lbl_801E9D24.scene->mode;
    if (mode->mode != 5 || mode->submode != 2)
        fn_80058CB8(lbl_801E9D24.scene->mode, 0x238C, Handle_80020834());
    fn_80257828(self->controller, 0x4A, 0x7E, 0);
    SceneControlService* service = fn_8007D074();
    service->active = 1;
    if (lbl_803776B8 && lbl_803776B8->first)
        fn_8006803C(lbl_803776B8, self->actor->record);
}
