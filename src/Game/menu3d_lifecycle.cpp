// Reconstructed from the Menu3D factory, original callbacks and native cleanup.
#include "menu3d_lifecycle_internal.h"

Menu3D_802193C0::~Menu3D_802193C0(){vtable=__vt__15Menu3D_802193C0;}

extern "C" {
void fn_8021894C(Menu3D_802193C0*);
extern const float lbl_8037AE90,lbl_8037AE94,lbl_8037AE98,lbl_8037AE9C;
float fn_80284FA8(float);
void fn_802180D0(Menu3D_802193C0* self) {
 fn_802139D8(reinterpret_cast<Activable_Z*>(self));
 fn_801E1F3C(&lbl_801E9D24.renderSlots[self->selector],Menu3DHandle(self->getIdentity()));
}
void fn_80218174(Menu3D_802193C0* self,unsigned char selector) {
 self->selector=selector;
 fn_80213A18(reinterpret_cast<Activable_Z*>(self));
 fn_8021894C(self);
 fn_801E2074(&lbl_801E9D24.renderSlots[self->selector],Menu3DHandle(self->getIdentity()),0);
}
void fn_80218228(Menu3D_802193C0*self,float){float value=lbl_8037AE90*(lbl_8037AE94+fn_80284FA8(lbl_8037AE98*self->accumulated)); self->pulse=value*lbl_8037AE9C;}
}
