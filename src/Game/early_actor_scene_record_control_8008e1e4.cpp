#include "Game/early_actor_scene_record_control_views.h"
extern "C" void fn_8008E1E4(SceneRecordOwner* self,double delta) {
    if(lbl_801E9D24.system->enabled)
        fn_8007D6A0(&self->actor->record,fn_80092844(self->actor));
    fn_80092DAC(self->actor,delta);
}
