#include "Game/early_actor_scene_control_views.h"
extern "C" void fn_8008C2DC(SceneControlOwner* self) {
    if (lbl_803776B8 && lbl_803776B8->second)
        fn_80068158(lbl_803776B8, self->actor->record);
    self->actor->flags &= ~0x80000000ULL;
}
