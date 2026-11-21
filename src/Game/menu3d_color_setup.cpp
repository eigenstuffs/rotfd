#include "menu_color_setup_internal.h"
extern "C" {
void fn_8021894C(Menu3DColorSetup*,int);
void fn_8021D51C(void*,int);
extern const float lbl_8037AE9C,lbl_8037AE94;
void fn_80219060(Menu3DColorSetup*self,int value) {
    fn_8021894C(self,value);
    fn_8021D51C(self,value);
    self->start.scale(lbl_8037AE9C);
    self->end.scale(lbl_8037AE9C);
    self->startSelect.scale(lbl_8037AE9C);
    self->endSelect.scale(lbl_8037AE9C);
    self->grey.scale(lbl_8037AE9C);
    self->greyAlpha=lbl_8037AE94;
}
}
