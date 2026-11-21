#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802B9B78 = {
    {
        { &lbl_80374D40, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802B9B84 = {
    {
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802B9B98 = {
    {
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
        { &lbl_80374D50, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802B9BB4 = {
    {
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
        { &lbl_80374D50, 0 }, // Manipulator_Z
        { &lbl_80374D58, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802B9BD8 = {
    {
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
        { &lbl_80374D50, 0 }, // Manipulator_Z
        { &lbl_80374D58, 0 }, // ObjectMove_Z
        { &lbl_80374D60, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802B9C04 = {
    {
        { &lbl_80374D38, 792 }, // CFSM
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
        { &lbl_80374D50, 0 }, // Manipulator_Z
        { &lbl_80374D58, 0 }, // ObjectMove_Z
        { &lbl_80374D60, 0 }, // ObjectThrow_Z
        { &lbl_80374D68, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CNPCMove.
NativeRuntimeBaseList<8> lbl_802B9C40 = {
    {
        { &lbl_80374D38, 792 }, // CFSM
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
        { &lbl_80374D50, 0 }, // Manipulator_Z
        { &lbl_80374D58, 0 }, // ObjectMove_Z
        { &lbl_80374D60, 0 }, // ObjectThrow_Z
        { &lbl_80374D68, 0 }, // LodMove_Z
        { &lbl_80374D70, 0 }, // CActorMove
    }, 0
};

// Base hierarchy for CJellyfishMove.
NativeRuntimeBaseList<9> lbl_802B9C84 = {
    {
        { &lbl_80374D38, 792 }, // CFSM
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
        { &lbl_80374D50, 0 }, // Manipulator_Z
        { &lbl_80374D58, 0 }, // ObjectMove_Z
        { &lbl_80374D60, 0 }, // ObjectThrow_Z
        { &lbl_80374D68, 0 }, // LodMove_Z
        { &lbl_80374D70, 0 }, // CActorMove
        { &lbl_80374D78, 0 }, // CNPCMove
    }, 0
};

// Base hierarchy for CGreenJfishMove.
NativeRuntimeBaseList<10> lbl_802B9CD0 = {
    {
        { &lbl_80374D38, 792 }, // CFSM
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
        { &lbl_80374D50, 0 }, // Manipulator_Z
        { &lbl_80374D58, 0 }, // ObjectMove_Z
        { &lbl_80374D60, 0 }, // ObjectThrow_Z
        { &lbl_80374D68, 0 }, // LodMove_Z
        { &lbl_80374D70, 0 }, // CActorMove
        { &lbl_80374D78, 0 }, // CNPCMove
        { &lbl_80374D80, 0 }, // CJellyfishMove
    }, 0
};

}
