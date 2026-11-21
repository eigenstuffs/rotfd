#include "Game/early_misc_event_control_views.h"
extern "C"float fn_80079024(MiscAngleOwner*self){if(self->mode!=2&&self->mode!=3){MiscVector v;fn_800784A8(self,&v);float result=lbl_8037899C;if(result!=v.z||result!=v.x)result=lbl_803789EC*fn_80285124(v.z,v.x);return result;}else return lbl_8037899C;}
