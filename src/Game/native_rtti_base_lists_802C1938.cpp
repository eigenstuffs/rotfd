#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802C1938 = {
    {
        { &lbl_80375940, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802C1944 = {
    {
        { &lbl_80375940, 0 }, // BaseObject_Z
        { &lbl_80375948, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802C1958 = {
    {
        { &lbl_80375940, 0 }, // BaseObject_Z
        { &lbl_80375948, 0 }, // Activable_Z
        { &lbl_80375950, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802C1974 = {
    {
        { &lbl_80375940, 0 }, // BaseObject_Z
        { &lbl_80375948, 0 }, // Activable_Z
        { &lbl_80375950, 0 }, // Manipulator_Z
        { &lbl_80375958, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802C1998 = {
    {
        { &lbl_80375940, 0 }, // BaseObject_Z
        { &lbl_80375948, 0 }, // Activable_Z
        { &lbl_80375950, 0 }, // Manipulator_Z
        { &lbl_80375958, 0 }, // ObjectMove_Z
        { &lbl_80375960, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802C19C4 = {
    {
        { &lbl_80375938, 792 }, // CFSM
        { &lbl_80375940, 0 }, // BaseObject_Z
        { &lbl_80375948, 0 }, // Activable_Z
        { &lbl_80375950, 0 }, // Manipulator_Z
        { &lbl_80375958, 0 }, // ObjectMove_Z
        { &lbl_80375960, 0 }, // ObjectThrow_Z
        { &lbl_80375968, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CRBObjBaseMove.
NativeRuntimeBaseList<8> lbl_802C1A00 = {
    {
        { &lbl_80375938, 792 }, // CFSM
        { &lbl_80375940, 0 }, // BaseObject_Z
        { &lbl_80375948, 0 }, // Activable_Z
        { &lbl_80375950, 0 }, // Manipulator_Z
        { &lbl_80375958, 0 }, // ObjectMove_Z
        { &lbl_80375960, 0 }, // ObjectThrow_Z
        { &lbl_80375968, 0 }, // LodMove_Z
        { &lbl_80375970, 0 }, // CActorMove
    }, 0
};

// Base hierarchy for CQSnailMove.
NativeRuntimeBaseList<9> lbl_802C1A44 = {
    {
        { &lbl_80375938, 792 }, // CFSM
        { &lbl_80375940, 0 }, // BaseObject_Z
        { &lbl_80375948, 0 }, // Activable_Z
        { &lbl_80375950, 0 }, // Manipulator_Z
        { &lbl_80375958, 0 }, // ObjectMove_Z
        { &lbl_80375960, 0 }, // ObjectThrow_Z
        { &lbl_80375968, 0 }, // LodMove_Z
        { &lbl_80375970, 0 }, // CActorMove
        { &lbl_80375978, 0 }, // CRBObjBaseMove
    }, 0
};

}
