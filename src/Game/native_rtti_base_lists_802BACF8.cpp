#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BACF8 = {
    {
        { &lbl_80374F48, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BAD04 = {
    {
        { &lbl_80374F48, 0 }, // BaseObject_Z
        { &lbl_80374F50, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802BAD18 = {
    {
        { &lbl_80374F48, 0 }, // BaseObject_Z
        { &lbl_80374F50, 0 }, // Activable_Z
        { &lbl_80374F58, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802BAD34 = {
    {
        { &lbl_80374F48, 0 }, // BaseObject_Z
        { &lbl_80374F50, 0 }, // Activable_Z
        { &lbl_80374F58, 0 }, // Manipulator_Z
        { &lbl_80374F60, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802BAD58 = {
    {
        { &lbl_80374F48, 0 }, // BaseObject_Z
        { &lbl_80374F50, 0 }, // Activable_Z
        { &lbl_80374F58, 0 }, // Manipulator_Z
        { &lbl_80374F60, 0 }, // ObjectMove_Z
        { &lbl_80374F68, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802BAD84 = {
    {
        { &lbl_80374F40, 792 }, // CFSM
        { &lbl_80374F48, 0 }, // BaseObject_Z
        { &lbl_80374F50, 0 }, // Activable_Z
        { &lbl_80374F58, 0 }, // Manipulator_Z
        { &lbl_80374F60, 0 }, // ObjectMove_Z
        { &lbl_80374F68, 0 }, // ObjectThrow_Z
        { &lbl_80374F70, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CNPCMove.
NativeRuntimeBaseList<8> lbl_802BADC0 = {
    {
        { &lbl_80374F40, 792 }, // CFSM
        { &lbl_80374F48, 0 }, // BaseObject_Z
        { &lbl_80374F50, 0 }, // Activable_Z
        { &lbl_80374F58, 0 }, // Manipulator_Z
        { &lbl_80374F60, 0 }, // ObjectMove_Z
        { &lbl_80374F68, 0 }, // ObjectThrow_Z
        { &lbl_80374F70, 0 }, // LodMove_Z
        { &lbl_80374F78, 0 }, // CActorMove
    }, 0
};

}
