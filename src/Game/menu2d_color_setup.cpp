#include "menu_color_setup_internal.h"
extern "C" {
void fn_80216228(Menu2DColorSetup*,int);
void fn_8021D51C(void*,int);
extern const float lbl_8037AD74,lbl_8037AD6C;
void fn_8021693C(Menu2DColorSetup*self,int value) {
    fn_80216228(self,value);
    fn_8021D51C(self,value);
    self->start.scale(lbl_8037AD74);
    self->end.scale(lbl_8037AD74);
    self->startSelect.scale(lbl_8037AD74);
    self->endSelect.scale(lbl_8037AD74);
    self->grey.scale(lbl_8037AD74);
    self->greyAlpha=lbl_8037AD6C;
}
}
