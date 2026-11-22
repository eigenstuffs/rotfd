#include "Game/scene_callbacks_more.h"

extern "C" void slot38__11CQSnailMoveFf(SceneCallbacksMore::Actor*self,float delta){self->elapsed+=delta;if(self->elapsed>=lbl_803796BC){self->elapsed=lbl_803796B0;if(fn_801F1224(0,1)==0&&fn_8007D604(self->component,0)){fn_800CCCEC(self);fn_8007D6A0(self->component,3);}else if(fn_8007D604(self->component,3))fn_8007D6A0(self->component,0);}fn_8007DA74(self->component,delta);fn_800A905C(self,delta);}
