#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BCCC8 = {
    {
        { &lbl_80375388, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BCCD4 = {
    {
        { &lbl_80375388, 0 }, // BaseObject_Z
        { &lbl_80375390, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802BCCE8 = {
    {
        { &lbl_80375388, 0 }, // BaseObject_Z
        { &lbl_80375390, 0 }, // Activable_Z
        { &lbl_80375398, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for CTileMove.
NativeRuntimeBaseList<5> lbl_802BCD04 = {
    {
        { &lbl_80375380, 360 }, // CFSM
        { &lbl_80375388, 0 }, // BaseObject_Z
        { &lbl_80375390, 0 }, // Activable_Z
        { &lbl_80375398, 0 }, // Manipulator_Z
        { &lbl_803753A0, 0 }, // ObjectMove_Z
    }, 0
};

}
