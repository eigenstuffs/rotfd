#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BA2D8 = {
    {
        { &lbl_80374E28, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BA2E4 = {
    {
        { &lbl_80374E28, 0 }, // BaseObject_Z
        { &lbl_80374E30, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802BA2F8 = {
    {
        { &lbl_80374E28, 0 }, // BaseObject_Z
        { &lbl_80374E30, 0 }, // Activable_Z
        { &lbl_80374E38, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802BA314 = {
    {
        { &lbl_80374E28, 0 }, // BaseObject_Z
        { &lbl_80374E30, 0 }, // Activable_Z
        { &lbl_80374E38, 0 }, // Manipulator_Z
        { &lbl_80374E40, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802BA338 = {
    {
        { &lbl_80374E28, 0 }, // BaseObject_Z
        { &lbl_80374E30, 0 }, // Activable_Z
        { &lbl_80374E38, 0 }, // Manipulator_Z
        { &lbl_80374E40, 0 }, // ObjectMove_Z
        { &lbl_80374E48, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802BA364 = {
    {
        { &lbl_80374E20, 792 }, // CFSM
        { &lbl_80374E28, 0 }, // BaseObject_Z
        { &lbl_80374E30, 0 }, // Activable_Z
        { &lbl_80374E38, 0 }, // Manipulator_Z
        { &lbl_80374E40, 0 }, // ObjectMove_Z
        { &lbl_80374E48, 0 }, // ObjectThrow_Z
        { &lbl_80374E50, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CNPCMove.
NativeRuntimeBaseList<8> lbl_802BA3A0 = {
    {
        { &lbl_80374E20, 792 }, // CFSM
        { &lbl_80374E28, 0 }, // BaseObject_Z
        { &lbl_80374E30, 0 }, // Activable_Z
        { &lbl_80374E38, 0 }, // Manipulator_Z
        { &lbl_80374E40, 0 }, // ObjectMove_Z
        { &lbl_80374E48, 0 }, // ObjectThrow_Z
        { &lbl_80374E50, 0 }, // LodMove_Z
        { &lbl_80374E58, 0 }, // CActorMove
    }, 0
};

// Base hierarchy for CJellyfishMove.
NativeRuntimeBaseList<9> lbl_802BA3E4 = {
    {
        { &lbl_80374E20, 792 }, // CFSM
        { &lbl_80374E28, 0 }, // BaseObject_Z
        { &lbl_80374E30, 0 }, // Activable_Z
        { &lbl_80374E38, 0 }, // Manipulator_Z
        { &lbl_80374E40, 0 }, // ObjectMove_Z
        { &lbl_80374E48, 0 }, // ObjectThrow_Z
        { &lbl_80374E50, 0 }, // LodMove_Z
        { &lbl_80374E58, 0 }, // CActorMove
        { &lbl_80374E60, 0 }, // CNPCMove
    }, 0
};

// Base hierarchy for CRedJfishMove.
NativeRuntimeBaseList<10> lbl_802BA430 = {
    {
        { &lbl_80374E20, 792 }, // CFSM
        { &lbl_80374E28, 0 }, // BaseObject_Z
        { &lbl_80374E30, 0 }, // Activable_Z
        { &lbl_80374E38, 0 }, // Manipulator_Z
        { &lbl_80374E40, 0 }, // ObjectMove_Z
        { &lbl_80374E48, 0 }, // ObjectThrow_Z
        { &lbl_80374E50, 0 }, // LodMove_Z
        { &lbl_80374E58, 0 }, // CActorMove
        { &lbl_80374E60, 0 }, // CNPCMove
        { &lbl_80374E68, 0 }, // CJellyfishMove
    }, 0
};

}
