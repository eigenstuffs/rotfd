#include "menu_constructor_internal.h"
extern "C" { extern const float lbl_8037AECC,lbl_8037AE94,lbl_8037AE90,lbl_8037AE9C,lbl_8037AED0,lbl_8037AEB8; }
Menu3D_802193C0::Menu3D_802193C0() : MenuBase_8021D7E4(0,6) {
    startLine=0;
    field2C=0;
    bitmap=MenuHandle2();
    scale=lbl_8037AECC;
    pulse=lbl_8037AE90;
    start.set(lbl_8037AE94,lbl_8037AE9C,lbl_8037AE9C);
    end.set(lbl_8037AE9C,lbl_8037AED0,lbl_8037AED0);
    startSelect.set(lbl_8037AE94,lbl_8037AE94,lbl_8037AE94);
    endSelect.set(lbl_8037AE94,lbl_8037AE9C,lbl_8037AE9C);
    grey.set(lbl_8037AE94,lbl_8037AEB8,lbl_8037AEB8,lbl_8037AE9C);
    font=0;
}
