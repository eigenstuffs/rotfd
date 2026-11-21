#include "Game/early_actor_scene_record_control_views.h"
extern "C" void fn_8008D6EC(SceneRecordOwner* self) {
    self->actor->flags |= 0x1000000000ULL;
    fn_8008D86C(self);
    if(lbl_803776B8 && lbl_803776B8->first)
        fn_8006803C(lbl_803776B8,self->actor->record.key);
}
