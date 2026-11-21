#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BBD40 = {
    {
        { &lbl_80375158, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BBD4C = {
    {
        { &lbl_80375158, 0 }, // BaseObject_Z
        { &lbl_80375160, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802BBD60 = {
    {
        { &lbl_80375158, 0 }, // BaseObject_Z
        { &lbl_80375160, 0 }, // Activable_Z
        { &lbl_80375168, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802BBD7C = {
    {
        { &lbl_80375158, 0 }, // BaseObject_Z
        { &lbl_80375160, 0 }, // Activable_Z
        { &lbl_80375168, 0 }, // Manipulator_Z
        { &lbl_80375170, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802BBDA0 = {
    {
        { &lbl_80375158, 0 }, // BaseObject_Z
        { &lbl_80375160, 0 }, // Activable_Z
        { &lbl_80375168, 0 }, // Manipulator_Z
        { &lbl_80375170, 0 }, // ObjectMove_Z
        { &lbl_80375178, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802BBDCC = {
    {
        { &lbl_80375150, 792 }, // CFSM
        { &lbl_80375158, 0 }, // BaseObject_Z
        { &lbl_80375160, 0 }, // Activable_Z
        { &lbl_80375168, 0 }, // Manipulator_Z
        { &lbl_80375170, 0 }, // ObjectMove_Z
        { &lbl_80375178, 0 }, // ObjectThrow_Z
        { &lbl_80375180, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CScriptMove.
NativeRuntimeBaseList<8> lbl_802BBE08 = {
    {
        { &lbl_80375150, 792 }, // CFSM
        { &lbl_80375158, 0 }, // BaseObject_Z
        { &lbl_80375160, 0 }, // Activable_Z
        { &lbl_80375168, 0 }, // Manipulator_Z
        { &lbl_80375170, 0 }, // ObjectMove_Z
        { &lbl_80375178, 0 }, // ObjectThrow_Z
        { &lbl_80375180, 0 }, // LodMove_Z
        { &lbl_80375188, 0 }, // CActorMove
    }, 0
};

// Base hierarchy for CSimpleMove.
NativeRuntimeBaseList<9> lbl_802BBE4C = {
    {
        { &lbl_80375150, 792 }, // CFSM
        { &lbl_80375158, 0 }, // BaseObject_Z
        { &lbl_80375160, 0 }, // Activable_Z
        { &lbl_80375168, 0 }, // Manipulator_Z
        { &lbl_80375170, 0 }, // ObjectMove_Z
        { &lbl_80375178, 0 }, // ObjectThrow_Z
        { &lbl_80375180, 0 }, // LodMove_Z
        { &lbl_80375188, 0 }, // CActorMove
        { &lbl_80375190, 0 }, // CScriptMove
    }, 0
};

}
