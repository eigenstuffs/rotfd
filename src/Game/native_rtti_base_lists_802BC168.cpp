#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BC168 = {
    {
        { &lbl_803751F0, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BC174 = {
    {
        { &lbl_803751F0, 0 }, // BaseObject_Z
        { &lbl_803751F8, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802BC188 = {
    {
        { &lbl_803751F0, 0 }, // BaseObject_Z
        { &lbl_803751F8, 0 }, // Activable_Z
        { &lbl_80375200, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802BC1A4 = {
    {
        { &lbl_803751F0, 0 }, // BaseObject_Z
        { &lbl_803751F8, 0 }, // Activable_Z
        { &lbl_80375200, 0 }, // Manipulator_Z
        { &lbl_80375208, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802BC1C8 = {
    {
        { &lbl_803751F0, 0 }, // BaseObject_Z
        { &lbl_803751F8, 0 }, // Activable_Z
        { &lbl_80375200, 0 }, // Manipulator_Z
        { &lbl_80375208, 0 }, // ObjectMove_Z
        { &lbl_80375210, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802BC1F4 = {
    {
        { &lbl_803751E8, 792 }, // CFSM
        { &lbl_803751F0, 0 }, // BaseObject_Z
        { &lbl_803751F8, 0 }, // Activable_Z
        { &lbl_80375200, 0 }, // Manipulator_Z
        { &lbl_80375208, 0 }, // ObjectMove_Z
        { &lbl_80375210, 0 }, // ObjectThrow_Z
        { &lbl_80375218, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CScriptMove.
NativeRuntimeBaseList<8> lbl_802BC230 = {
    {
        { &lbl_803751E8, 792 }, // CFSM
        { &lbl_803751F0, 0 }, // BaseObject_Z
        { &lbl_803751F8, 0 }, // Activable_Z
        { &lbl_80375200, 0 }, // Manipulator_Z
        { &lbl_80375208, 0 }, // ObjectMove_Z
        { &lbl_80375210, 0 }, // ObjectThrow_Z
        { &lbl_80375218, 0 }, // LodMove_Z
        { &lbl_80375220, 0 }, // CActorMove
    }, 0
};

// Base hierarchy for CMediumMove.
NativeRuntimeBaseList<9> lbl_802BC274 = {
    {
        { &lbl_803751E8, 792 }, // CFSM
        { &lbl_803751F0, 0 }, // BaseObject_Z
        { &lbl_803751F8, 0 }, // Activable_Z
        { &lbl_80375200, 0 }, // Manipulator_Z
        { &lbl_80375208, 0 }, // ObjectMove_Z
        { &lbl_80375210, 0 }, // ObjectThrow_Z
        { &lbl_80375218, 0 }, // LodMove_Z
        { &lbl_80375220, 0 }, // CActorMove
        { &lbl_80375228, 0 }, // CScriptMove
    }, 0
};

}
