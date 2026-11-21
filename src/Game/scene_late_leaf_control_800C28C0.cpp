#include "Game/scene_late_leaf_controls.h"

extern "C" void fn_800C28C0(SceneLateLeaf::Object*self,float delta){if(self->timing){self->elapsed+=delta;if(self->elapsed>=self->duration){self->elapsed=lbl_8037951C;self->duration=lbl_8037951C;self->timing=0;fn_802603A0(lbl_801E9D24.scene,0xC2,lbl_801E9D24.scene->target,lbl_80379538);}}}
