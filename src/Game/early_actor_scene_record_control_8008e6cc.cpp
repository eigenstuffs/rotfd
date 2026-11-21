#include "Game/early_actor_scene_record_control_views.h"
extern "C" void fn_8008E6CC(SceneRecordOwner* self) {
    if(lbl_803776B8 && lbl_803776B8->first)
        fn_8006803C(lbl_803776B8,self->actor->record.key);
    resolveSceneRecord(lbl_801E9D24.scene->mode->target)->setColor(SceneRecordColor(lbl_80378B84,lbl_80378B84,lbl_80378B84,lbl_80378AF8),lbl_80378B88);
}
