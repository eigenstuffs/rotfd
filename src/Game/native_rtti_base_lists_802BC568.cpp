#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BC568 = {
    {
        { &lbl_80375278, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BC574 = {
    {
        { &lbl_80375278, 0 }, // BaseObject_Z
        { &lbl_80375280, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802BC588 = {
    {
        { &lbl_80375278, 0 }, // BaseObject_Z
        { &lbl_80375280, 0 }, // Activable_Z
        { &lbl_80375288, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802BC5A4 = {
    {
        { &lbl_80375278, 0 }, // BaseObject_Z
        { &lbl_80375280, 0 }, // Activable_Z
        { &lbl_80375288, 0 }, // Manipulator_Z
        { &lbl_80375290, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802BC5C8 = {
    {
        { &lbl_80375278, 0 }, // BaseObject_Z
        { &lbl_80375280, 0 }, // Activable_Z
        { &lbl_80375288, 0 }, // Manipulator_Z
        { &lbl_80375290, 0 }, // ObjectMove_Z
        { &lbl_80375298, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802BC5F4 = {
    {
        { &lbl_80375270, 792 }, // CFSM
        { &lbl_80375278, 0 }, // BaseObject_Z
        { &lbl_80375280, 0 }, // Activable_Z
        { &lbl_80375288, 0 }, // Manipulator_Z
        { &lbl_80375290, 0 }, // ObjectMove_Z
        { &lbl_80375298, 0 }, // ObjectThrow_Z
        { &lbl_803752A0, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CScriptMove.
NativeRuntimeBaseList<8> lbl_802BC630 = {
    {
        { &lbl_80375270, 792 }, // CFSM
        { &lbl_80375278, 0 }, // BaseObject_Z
        { &lbl_80375280, 0 }, // Activable_Z
        { &lbl_80375288, 0 }, // Manipulator_Z
        { &lbl_80375290, 0 }, // ObjectMove_Z
        { &lbl_80375298, 0 }, // ObjectThrow_Z
        { &lbl_803752A0, 0 }, // LodMove_Z
        { &lbl_803752A8, 0 }, // CActorMove
    }, 0
};

// Base hierarchy for CComplexMove.
NativeRuntimeBaseList<9> lbl_802BC674 = {
    {
        { &lbl_80375270, 792 }, // CFSM
        { &lbl_80375278, 0 }, // BaseObject_Z
        { &lbl_80375280, 0 }, // Activable_Z
        { &lbl_80375288, 0 }, // Manipulator_Z
        { &lbl_80375290, 0 }, // ObjectMove_Z
        { &lbl_80375298, 0 }, // ObjectThrow_Z
        { &lbl_803752A0, 0 }, // LodMove_Z
        { &lbl_803752A8, 0 }, // CActorMove
        { &lbl_803752B0, 0 }, // CScriptMove
    }, 0
};

}
