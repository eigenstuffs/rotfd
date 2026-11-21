#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802C82C8 = {
    {
        { &lbl_80375A00, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802C82D4 = {
    {
        { &lbl_80375A00, 0 }, // BaseObject_Z
        { &lbl_80375A08, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802C82E8 = {
    {
        { &lbl_80375A00, 0 }, // BaseObject_Z
        { &lbl_80375A08, 0 }, // Activable_Z
        { &lbl_80375A10, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for WaterHelmetMove.
NativeRuntimeBaseList<5> lbl_802C8304 = {
    {
        { &lbl_803759F8, 360 }, // CFSM
        { &lbl_80375A00, 0 }, // BaseObject_Z
        { &lbl_80375A08, 0 }, // Activable_Z
        { &lbl_80375A10, 0 }, // Manipulator_Z
        { &lbl_80375A18, 0 }, // ObjectMove_Z
    }, 0
};

}
