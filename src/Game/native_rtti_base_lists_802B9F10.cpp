#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802B9F10 = {
    {
        { &lbl_80374DB0, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802B9F1C = {
    {
        { &lbl_80374DB0, 0 }, // BaseObject_Z
        { &lbl_80374DB8, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802B9F30 = {
    {
        { &lbl_80374DB0, 0 }, // BaseObject_Z
        { &lbl_80374DB8, 0 }, // Activable_Z
        { &lbl_80374DC0, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802B9F4C = {
    {
        { &lbl_80374DB0, 0 }, // BaseObject_Z
        { &lbl_80374DB8, 0 }, // Activable_Z
        { &lbl_80374DC0, 0 }, // Manipulator_Z
        { &lbl_80374DC8, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802B9F70 = {
    {
        { &lbl_80374DB0, 0 }, // BaseObject_Z
        { &lbl_80374DB8, 0 }, // Activable_Z
        { &lbl_80374DC0, 0 }, // Manipulator_Z
        { &lbl_80374DC8, 0 }, // ObjectMove_Z
        { &lbl_80374DD0, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802B9F9C = {
    {
        { &lbl_80374DA8, 792 }, // CFSM
        { &lbl_80374DB0, 0 }, // BaseObject_Z
        { &lbl_80374DB8, 0 }, // Activable_Z
        { &lbl_80374DC0, 0 }, // Manipulator_Z
        { &lbl_80374DC8, 0 }, // ObjectMove_Z
        { &lbl_80374DD0, 0 }, // ObjectThrow_Z
        { &lbl_80374DD8, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CNPCMove.
NativeRuntimeBaseList<8> lbl_802B9FD8 = {
    {
        { &lbl_80374DA8, 792 }, // CFSM
        { &lbl_80374DB0, 0 }, // BaseObject_Z
        { &lbl_80374DB8, 0 }, // Activable_Z
        { &lbl_80374DC0, 0 }, // Manipulator_Z
        { &lbl_80374DC8, 0 }, // ObjectMove_Z
        { &lbl_80374DD0, 0 }, // ObjectThrow_Z
        { &lbl_80374DD8, 0 }, // LodMove_Z
        { &lbl_80374DE0, 0 }, // CActorMove
    }, 0
};

// Base hierarchy for CJellyfishMove.
NativeRuntimeBaseList<9> lbl_802BA01C = {
    {
        { &lbl_80374DA8, 792 }, // CFSM
        { &lbl_80374DB0, 0 }, // BaseObject_Z
        { &lbl_80374DB8, 0 }, // Activable_Z
        { &lbl_80374DC0, 0 }, // Manipulator_Z
        { &lbl_80374DC8, 0 }, // ObjectMove_Z
        { &lbl_80374DD0, 0 }, // ObjectThrow_Z
        { &lbl_80374DD8, 0 }, // LodMove_Z
        { &lbl_80374DE0, 0 }, // CActorMove
        { &lbl_80374DE8, 0 }, // CNPCMove
    }, 0
};

// Base hierarchy for CPinkJfishMove.
NativeRuntimeBaseList<10> lbl_802BA068 = {
    {
        { &lbl_80374DA8, 792 }, // CFSM
        { &lbl_80374DB0, 0 }, // BaseObject_Z
        { &lbl_80374DB8, 0 }, // Activable_Z
        { &lbl_80374DC0, 0 }, // Manipulator_Z
        { &lbl_80374DC8, 0 }, // ObjectMove_Z
        { &lbl_80374DD0, 0 }, // ObjectThrow_Z
        { &lbl_80374DD8, 0 }, // LodMove_Z
        { &lbl_80374DE0, 0 }, // CActorMove
        { &lbl_80374DE8, 0 }, // CNPCMove
        { &lbl_80374DF0, 0 }, // CJellyfishMove
    }, 0
};

}
