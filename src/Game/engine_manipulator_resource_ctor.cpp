#include "Game/engine_manipulator_resource_ctor.h"

ViewportManipulator_802EB130::ViewportManipulator_802EB130(){
 field2C=lbl_8037ABF8;field28=lbl_8037ABF8;field24=lbl_8037ABFC;field20=lbl_8037ABFC;field34=lbl_8037AC00;field30=lbl_8037AC00;field4C=0;
 assign(handle48,ManipulatorCopy(fn_801B550C(lbl_801E9D24.manager,ManipulatorName(lbl_8037AC04),ManipulatorName(lbl_802AE538))));
 setTarget(resolve(handle48),ManipulatorCopy(fn_801B550C(lbl_801E9D24.manager,ManipulatorName(lbl_8037AC0C),ManipulatorName(lbl_802AE54C))));
}
