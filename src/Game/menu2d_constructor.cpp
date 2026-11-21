#include "menu_constructor_internal.h"
extern "C" { extern const float lbl_8037AD6C,lbl_8037AD68,lbl_8037AD74,lbl_8037ADA4,lbl_8037AD90; }
Menu2D_80216C9C::Menu2D_80216C9C() : MenuBase_8021D7E4(0,6) {
    startLine=0;
    field2C=0;
    bitmap=MenuHandle2();
    scale=lbl_8037AD6C;
    pulse=lbl_8037AD68;
    start.set(lbl_8037AD6C,lbl_8037AD74,lbl_8037AD74);
    end.set(lbl_8037AD74,lbl_8037ADA4,lbl_8037ADA4);
    startSelect.set(lbl_8037AD6C,lbl_8037AD6C,lbl_8037AD6C);
    endSelect.set(lbl_8037AD6C,lbl_8037AD74,lbl_8037AD74);
    grey.set(lbl_8037AD6C,lbl_8037AD90,lbl_8037AD90,lbl_8037AD74);
    font=0;
}
