#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802B92E8 = {
    {
        { &lbl_80374C10, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802B92F4 = {
    {
        { &lbl_80374C10, 0 }, // BaseObject_Z
        { &lbl_80374C18, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802B9308 = {
    {
        { &lbl_80374C10, 0 }, // BaseObject_Z
        { &lbl_80374C18, 0 }, // Activable_Z
        { &lbl_80374C20, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802B9324 = {
    {
        { &lbl_80374C10, 0 }, // BaseObject_Z
        { &lbl_80374C18, 0 }, // Activable_Z
        { &lbl_80374C20, 0 }, // Manipulator_Z
        { &lbl_80374C28, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802B9348 = {
    {
        { &lbl_80374C10, 0 }, // BaseObject_Z
        { &lbl_80374C18, 0 }, // Activable_Z
        { &lbl_80374C20, 0 }, // Manipulator_Z
        { &lbl_80374C28, 0 }, // ObjectMove_Z
        { &lbl_80374C30, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802B9374 = {
    {
        { &lbl_80374C08, 792 }, // CFSM
        { &lbl_80374C10, 0 }, // BaseObject_Z
        { &lbl_80374C18, 0 }, // Activable_Z
        { &lbl_80374C20, 0 }, // Manipulator_Z
        { &lbl_80374C28, 0 }, // ObjectMove_Z
        { &lbl_80374C30, 0 }, // ObjectThrow_Z
        { &lbl_80374C38, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CSpongeBobMove.
NativeRuntimeBaseList<8> lbl_802B93B0 = {
    {
        { &lbl_80374C08, 792 }, // CFSM
        { &lbl_80374C10, 0 }, // BaseObject_Z
        { &lbl_80374C18, 0 }, // Activable_Z
        { &lbl_80374C20, 0 }, // Manipulator_Z
        { &lbl_80374C28, 0 }, // ObjectMove_Z
        { &lbl_80374C30, 0 }, // ObjectThrow_Z
        { &lbl_80374C38, 0 }, // LodMove_Z
        { &lbl_80374C40, 0 }, // CActorMove
    }, 0
};

}
