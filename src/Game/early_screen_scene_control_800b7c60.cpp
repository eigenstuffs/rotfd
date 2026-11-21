#include "Game/early_screen_scene_control_views.h"
extern "C" void fn_800B7C60(ScreenSceneOwner*self){
 fn_80260F64(self);
 if(self->first)self->first->clear();
 if(self->mode){if(validScreen(fn_800BCEF8(self)))resolveScreen(fn_800BCEF8(self))->clear();}
 if(self->other)self->other->clear();
 if(self->message)self->message->clear();
 if(lbl_801E9D24.service->object)lbl_801E9D24.service->object->clear();
 if(self->second)self->second->clear();
 if(fn_801F7EB8(&self->related))resolveScreen(self->related)->clear();
}
