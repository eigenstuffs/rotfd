#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802B0648 = {
    {
        { &lbl_80373F28, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802B0654 = {
    {
        { &lbl_80373F28, 0 }, // BaseObject_Z
        { &lbl_80373F30, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802B0668 = {
    {
        { &lbl_80373F28, 0 }, // BaseObject_Z
        { &lbl_80373F30, 0 }, // Activable_Z
        { &lbl_80373F38, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802B0684 = {
    {
        { &lbl_80373F28, 0 }, // BaseObject_Z
        { &lbl_80373F30, 0 }, // Activable_Z
        { &lbl_80373F38, 0 }, // Manipulator_Z
        { &lbl_80373F40, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802B06A8 = {
    {
        { &lbl_80373F28, 0 }, // BaseObject_Z
        { &lbl_80373F30, 0 }, // Activable_Z
        { &lbl_80373F38, 0 }, // Manipulator_Z
        { &lbl_80373F40, 0 }, // ObjectMove_Z
        { &lbl_80373F48, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for VehiculeMove_Z.
NativeRuntimeBaseList<6> lbl_802B06D4 = {
    {
        { &lbl_80373F28, 0 }, // BaseObject_Z
        { &lbl_80373F30, 0 }, // Activable_Z
        { &lbl_80373F38, 0 }, // Manipulator_Z
        { &lbl_80373F40, 0 }, // ObjectMove_Z
        { &lbl_80373F48, 0 }, // ObjectThrow_Z
        { &lbl_80373F50, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CHookMove.
NativeRuntimeBaseList<8> lbl_802B0708 = {
    {
        { &lbl_80373F20, 792 }, // CFSM
        { &lbl_80373F28, 0 }, // BaseObject_Z
        { &lbl_80373F30, 0 }, // Activable_Z
        { &lbl_80373F38, 0 }, // Manipulator_Z
        { &lbl_80373F40, 0 }, // ObjectMove_Z
        { &lbl_80373F48, 0 }, // ObjectThrow_Z
        { &lbl_80373F50, 0 }, // LodMove_Z
        { &lbl_80373F58, 0 }, // VehiculeMove_Z
    }, 0
};

}
