#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BA6A0 = {
    {
        { &lbl_80374EA0, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BA6AC = {
    {
        { &lbl_80374EA0, 0 }, // BaseObject_Z
        { &lbl_80374EA8, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802BA6C0 = {
    {
        { &lbl_80374EA0, 0 }, // BaseObject_Z
        { &lbl_80374EA8, 0 }, // Activable_Z
        { &lbl_80374EB0, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802BA6DC = {
    {
        { &lbl_80374EA0, 0 }, // BaseObject_Z
        { &lbl_80374EA8, 0 }, // Activable_Z
        { &lbl_80374EB0, 0 }, // Manipulator_Z
        { &lbl_80374EB8, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802BA700 = {
    {
        { &lbl_80374EA0, 0 }, // BaseObject_Z
        { &lbl_80374EA8, 0 }, // Activable_Z
        { &lbl_80374EB0, 0 }, // Manipulator_Z
        { &lbl_80374EB8, 0 }, // ObjectMove_Z
        { &lbl_80374EC0, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802BA72C = {
    {
        { &lbl_80374E98, 792 }, // CFSM
        { &lbl_80374EA0, 0 }, // BaseObject_Z
        { &lbl_80374EA8, 0 }, // Activable_Z
        { &lbl_80374EB0, 0 }, // Manipulator_Z
        { &lbl_80374EB8, 0 }, // ObjectMove_Z
        { &lbl_80374EC0, 0 }, // ObjectThrow_Z
        { &lbl_80374EC8, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CNPCMove.
NativeRuntimeBaseList<8> lbl_802BA768 = {
    {
        { &lbl_80374E98, 792 }, // CFSM
        { &lbl_80374EA0, 0 }, // BaseObject_Z
        { &lbl_80374EA8, 0 }, // Activable_Z
        { &lbl_80374EB0, 0 }, // Manipulator_Z
        { &lbl_80374EB8, 0 }, // ObjectMove_Z
        { &lbl_80374EC0, 0 }, // ObjectThrow_Z
        { &lbl_80374EC8, 0 }, // LodMove_Z
        { &lbl_80374ED0, 0 }, // CActorMove
    }, 0
};

// Base hierarchy for CJellyfishMove.
NativeRuntimeBaseList<9> lbl_802BA7AC = {
    {
        { &lbl_80374E98, 792 }, // CFSM
        { &lbl_80374EA0, 0 }, // BaseObject_Z
        { &lbl_80374EA8, 0 }, // Activable_Z
        { &lbl_80374EB0, 0 }, // Manipulator_Z
        { &lbl_80374EB8, 0 }, // ObjectMove_Z
        { &lbl_80374EC0, 0 }, // ObjectThrow_Z
        { &lbl_80374EC8, 0 }, // LodMove_Z
        { &lbl_80374ED0, 0 }, // CActorMove
        { &lbl_80374ED8, 0 }, // CNPCMove
    }, 0
};

// Base hierarchy for CBlueJfishMove.
NativeRuntimeBaseList<10> lbl_802BA7F8 = {
    {
        { &lbl_80374E98, 792 }, // CFSM
        { &lbl_80374EA0, 0 }, // BaseObject_Z
        { &lbl_80374EA8, 0 }, // Activable_Z
        { &lbl_80374EB0, 0 }, // Manipulator_Z
        { &lbl_80374EB8, 0 }, // ObjectMove_Z
        { &lbl_80374EC0, 0 }, // ObjectThrow_Z
        { &lbl_80374EC8, 0 }, // LodMove_Z
        { &lbl_80374ED0, 0 }, // CActorMove
        { &lbl_80374ED8, 0 }, // CNPCMove
        { &lbl_80374EE0, 0 }, // CJellyfishMove
    }, 0
};

}
