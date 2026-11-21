#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802B81B8 = {
    {
        { &lbl_80374940, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802B81C4 = {
    {
        { &lbl_80374940, 0 }, // BaseObject_Z
        { &lbl_80374948, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802B81D8 = {
    {
        { &lbl_80374940, 0 }, // BaseObject_Z
        { &lbl_80374948, 0 }, // Activable_Z
        { &lbl_80374950, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for CTreasureChestMove.
NativeRuntimeBaseList<5> lbl_802B81F4 = {
    {
        { &lbl_80374938, 360 }, // CFSM
        { &lbl_80374940, 0 }, // BaseObject_Z
        { &lbl_80374948, 0 }, // Activable_Z
        { &lbl_80374950, 0 }, // Manipulator_Z
        { &lbl_80374958, 0 }, // ObjectMove_Z
    }, 0
};

}
