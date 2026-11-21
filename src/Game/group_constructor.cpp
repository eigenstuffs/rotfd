extern "C" {
extern const char lbl_802AD8D8[14] = "TmpCameraUser";
extern const char lbl_802AD8E8[11] = "CameraUser";
}

#include "group_constructor_internal.h"

// Original class name is unknown; this constructor owns the fixed group slots.
Group_801FFC94::Group_801FFC94() {
    for (int i = 0; i < 4; ++i) {
        flags[i] = 0;
        fixed[i] = GroupTypedHandle(fn_801B550C(lbl_801E9D24.manager,
            NameHash(lbl_802AD8E8), NameHash(lbl_802AD8D8)));
        fixed[i].get()->order = i;
        fixed[i].get()->identifier = i;
    }
    paused = 0;
}
