#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802C9698 = {
    {
        { &lbl_80375CA8, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802C96A4 = {
    {
        { &lbl_80375CA8, 0 }, // BaseObject_Z
        { &lbl_80375CB0, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for CGCMemCardManipulator.
NativeRuntimeBaseList<4> lbl_802C96B8 = {
    {
        { &lbl_80375CA0, 32 }, // CFSM
        { &lbl_80375CA8, 0 }, // BaseObject_Z
        { &lbl_80375CB0, 0 }, // Activable_Z
        { &lbl_80375CB8, 0 }, // Manipulator_Z
    }, 0
};

}
