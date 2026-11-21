#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BA9F8 = {
    {
        { &lbl_80374EF8, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BAA04 = {
    {
        { &lbl_80374EF8, 0 }, // BaseObject_Z
        { &lbl_80374F00, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802BAA18 = {
    {
        { &lbl_80374EF8, 0 }, // BaseObject_Z
        { &lbl_80374F00, 0 }, // Activable_Z
        { &lbl_80374F08, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802BAA34 = {
    {
        { &lbl_80374EF8, 0 }, // BaseObject_Z
        { &lbl_80374F00, 0 }, // Activable_Z
        { &lbl_80374F08, 0 }, // Manipulator_Z
        { &lbl_80374F10, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802BAA58 = {
    {
        { &lbl_80374EF8, 0 }, // BaseObject_Z
        { &lbl_80374F00, 0 }, // Activable_Z
        { &lbl_80374F08, 0 }, // Manipulator_Z
        { &lbl_80374F10, 0 }, // ObjectMove_Z
        { &lbl_80374F18, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802BAA84 = {
    {
        { &lbl_80374EF0, 792 }, // CFSM
        { &lbl_80374EF8, 0 }, // BaseObject_Z
        { &lbl_80374F00, 0 }, // Activable_Z
        { &lbl_80374F08, 0 }, // Manipulator_Z
        { &lbl_80374F10, 0 }, // ObjectMove_Z
        { &lbl_80374F18, 0 }, // ObjectThrow_Z
        { &lbl_80374F20, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CNPCMove.
NativeRuntimeBaseList<8> lbl_802BAAC0 = {
    {
        { &lbl_80374EF0, 792 }, // CFSM
        { &lbl_80374EF8, 0 }, // BaseObject_Z
        { &lbl_80374F00, 0 }, // Activable_Z
        { &lbl_80374F08, 0 }, // Manipulator_Z
        { &lbl_80374F10, 0 }, // ObjectMove_Z
        { &lbl_80374F18, 0 }, // ObjectThrow_Z
        { &lbl_80374F20, 0 }, // LodMove_Z
        { &lbl_80374F28, 0 }, // CActorMove
    }, 0
};

// Base hierarchy for CJellyfishMove.
NativeRuntimeBaseList<9> lbl_802BAB04 = {
    {
        { &lbl_80374EF0, 792 }, // CFSM
        { &lbl_80374EF8, 0 }, // BaseObject_Z
        { &lbl_80374F00, 0 }, // Activable_Z
        { &lbl_80374F08, 0 }, // Manipulator_Z
        { &lbl_80374F10, 0 }, // ObjectMove_Z
        { &lbl_80374F18, 0 }, // ObjectThrow_Z
        { &lbl_80374F20, 0 }, // LodMove_Z
        { &lbl_80374F28, 0 }, // CActorMove
        { &lbl_80374F30, 0 }, // CNPCMove
    }, 0
};

}
