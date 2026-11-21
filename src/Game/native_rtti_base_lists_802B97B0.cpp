#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802B97B0 = {
    {
        { &lbl_80374CC8, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802B97BC = {
    {
        { &lbl_80374CC8, 0 }, // BaseObject_Z
        { &lbl_80374CD0, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802B97D0 = {
    {
        { &lbl_80374CC8, 0 }, // BaseObject_Z
        { &lbl_80374CD0, 0 }, // Activable_Z
        { &lbl_80374CD8, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802B97EC = {
    {
        { &lbl_80374CC8, 0 }, // BaseObject_Z
        { &lbl_80374CD0, 0 }, // Activable_Z
        { &lbl_80374CD8, 0 }, // Manipulator_Z
        { &lbl_80374CE0, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802B9810 = {
    {
        { &lbl_80374CC8, 0 }, // BaseObject_Z
        { &lbl_80374CD0, 0 }, // Activable_Z
        { &lbl_80374CD8, 0 }, // Manipulator_Z
        { &lbl_80374CE0, 0 }, // ObjectMove_Z
        { &lbl_80374CE8, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802B983C = {
    {
        { &lbl_80374CC0, 792 }, // CFSM
        { &lbl_80374CC8, 0 }, // BaseObject_Z
        { &lbl_80374CD0, 0 }, // Activable_Z
        { &lbl_80374CD8, 0 }, // Manipulator_Z
        { &lbl_80374CE0, 0 }, // ObjectMove_Z
        { &lbl_80374CE8, 0 }, // ObjectThrow_Z
        { &lbl_80374CF0, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CNPCMove.
NativeRuntimeBaseList<8> lbl_802B9878 = {
    {
        { &lbl_80374CC0, 792 }, // CFSM
        { &lbl_80374CC8, 0 }, // BaseObject_Z
        { &lbl_80374CD0, 0 }, // Activable_Z
        { &lbl_80374CD8, 0 }, // Manipulator_Z
        { &lbl_80374CE0, 0 }, // ObjectMove_Z
        { &lbl_80374CE8, 0 }, // ObjectThrow_Z
        { &lbl_80374CF0, 0 }, // LodMove_Z
        { &lbl_80374CF8, 0 }, // CActorMove
    }, 0
};

// Base hierarchy for CJellyfishMove.
NativeRuntimeBaseList<9> lbl_802B98BC = {
    {
        { &lbl_80374CC0, 792 }, // CFSM
        { &lbl_80374CC8, 0 }, // BaseObject_Z
        { &lbl_80374CD0, 0 }, // Activable_Z
        { &lbl_80374CD8, 0 }, // Manipulator_Z
        { &lbl_80374CE0, 0 }, // ObjectMove_Z
        { &lbl_80374CE8, 0 }, // ObjectThrow_Z
        { &lbl_80374CF0, 0 }, // LodMove_Z
        { &lbl_80374CF8, 0 }, // CActorMove
        { &lbl_80374D00, 0 }, // CNPCMove
    }, 0
};

// Base hierarchy for CYellowJfishMove.
NativeRuntimeBaseList<10> lbl_802B9908 = {
    {
        { &lbl_80374CC0, 792 }, // CFSM
        { &lbl_80374CC8, 0 }, // BaseObject_Z
        { &lbl_80374CD0, 0 }, // Activable_Z
        { &lbl_80374CD8, 0 }, // Manipulator_Z
        { &lbl_80374CE0, 0 }, // ObjectMove_Z
        { &lbl_80374CE8, 0 }, // ObjectThrow_Z
        { &lbl_80374CF0, 0 }, // LodMove_Z
        { &lbl_80374CF8, 0 }, // CActorMove
        { &lbl_80374D00, 0 }, // CNPCMove
        { &lbl_80374D08, 0 }, // CJellyfishMove
    }, 0
};

}
