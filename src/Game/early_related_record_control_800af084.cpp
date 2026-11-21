#include "Game/early_related_record_control_views.h"
extern "C"void fn_800AF084(RelatedRecordTimed*self,float delta){self->time+=delta;RelatedRecordActor*actor=resolveActor(self->owner->related);if(fn_8025E9FC(actor,0x3A)||fn_8025E9FC(actor,0x39)||self->time>=lbl_80379164)fn_8007D6A0((char*)self->owner+0x1F8,0);}
