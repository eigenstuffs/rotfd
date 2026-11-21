#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BF170 = {
    {
        { &lbl_80375630, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BF17C = {
    {
        { &lbl_80375630, 0 }, // BaseObject_Z
        { &lbl_80375638, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802BF190 = {
    {
        { &lbl_80375630, 0 }, // BaseObject_Z
        { &lbl_80375638, 0 }, // Activable_Z
        { &lbl_80375640, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802BF1AC = {
    {
        { &lbl_80375630, 0 }, // BaseObject_Z
        { &lbl_80375638, 0 }, // Activable_Z
        { &lbl_80375640, 0 }, // Manipulator_Z
        { &lbl_80375648, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802BF1D0 = {
    {
        { &lbl_80375630, 0 }, // BaseObject_Z
        { &lbl_80375638, 0 }, // Activable_Z
        { &lbl_80375640, 0 }, // Manipulator_Z
        { &lbl_80375648, 0 }, // ObjectMove_Z
        { &lbl_80375650, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CProjectileMove.
NativeRuntimeBaseList<7> lbl_802BF1FC = {
    {
        { &lbl_80375628, 792 }, // CFSM
        { &lbl_80375630, 0 }, // BaseObject_Z
        { &lbl_80375638, 0 }, // Activable_Z
        { &lbl_80375640, 0 }, // Manipulator_Z
        { &lbl_80375648, 0 }, // ObjectMove_Z
        { &lbl_80375650, 0 }, // ObjectThrow_Z
        { &lbl_80375658, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CBombMove.
NativeRuntimeBaseList<8> lbl_802BF238 = {
    {
        { &lbl_80375628, 792 }, // CFSM
        { &lbl_80375630, 0 }, // BaseObject_Z
        { &lbl_80375638, 0 }, // Activable_Z
        { &lbl_80375640, 0 }, // Manipulator_Z
        { &lbl_80375648, 0 }, // ObjectMove_Z
        { &lbl_80375650, 0 }, // ObjectThrow_Z
        { &lbl_80375658, 0 }, // LodMove_Z
        { &lbl_80375660, 0 }, // CProjectileMove
    }, 0
};

// Base hierarchy for CDBombMove.
NativeRuntimeBaseList<9> lbl_802BF27C = {
    {
        { &lbl_80375628, 792 }, // CFSM
        { &lbl_80375630, 0 }, // BaseObject_Z
        { &lbl_80375638, 0 }, // Activable_Z
        { &lbl_80375640, 0 }, // Manipulator_Z
        { &lbl_80375648, 0 }, // ObjectMove_Z
        { &lbl_80375650, 0 }, // ObjectThrow_Z
        { &lbl_80375658, 0 }, // LodMove_Z
        { &lbl_80375660, 0 }, // CProjectileMove
        { &lbl_80375668, 0 }, // CBombMove
    }, 0
};

}
