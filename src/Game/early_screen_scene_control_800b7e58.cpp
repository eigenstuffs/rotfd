#include "Game/early_screen_scene_control_views.h"
extern "C" void fn_800B7E58(ScreenSceneOwner*self){
 self->message=resolveScreen(fn_801B52EC(lbl_801E9D24.manager,agent_type_registry_CMsgBoxManipulator));
 self->other=resolveScreen(fn_801B52EC(lbl_801E9D24.manager,agent_type_registry_CMsgBoxManipulator));
 assignScreen(self->related,Handle_80021BCC(fn_801B52EC(lbl_801E9D24.manager,agent_type_registry_DisplayStaticImage)));
 lbl_80378160=fn_800BE2CC;lbl_80378164=fn_800BE8AC;
}
