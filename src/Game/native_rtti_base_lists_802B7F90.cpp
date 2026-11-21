#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802B7F90 = {
    {
        { &lbl_803748F0, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802B7F9C = {
    {
        { &lbl_803748F0, 0 }, // BaseObject_Z
        { &lbl_803748F8, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802B7FB0 = {
    {
        { &lbl_803748F0, 0 }, // BaseObject_Z
        { &lbl_803748F8, 0 }, // Activable_Z
        { &lbl_80374900, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for CCollectableMove.
NativeRuntimeBaseList<5> lbl_802B7FCC = {
    {
        { &lbl_803748E8, 360 }, // CFSM
        { &lbl_803748F0, 0 }, // BaseObject_Z
        { &lbl_803748F8, 0 }, // Activable_Z
        { &lbl_80374900, 0 }, // Manipulator_Z
        { &lbl_80374908, 0 }, // ObjectMove_Z
    }, 0
};

}
