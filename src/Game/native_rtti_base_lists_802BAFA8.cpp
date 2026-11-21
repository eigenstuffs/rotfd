#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BAFA8 = {
    {
        { &lbl_80374F90, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BAFB4 = {
    {
        { &lbl_80374F90, 0 }, // BaseObject_Z
        { &lbl_80374F98, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802BAFC8 = {
    {
        { &lbl_80374F90, 0 }, // BaseObject_Z
        { &lbl_80374F98, 0 }, // Activable_Z
        { &lbl_80374FA0, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802BAFE4 = {
    {
        { &lbl_80374F90, 0 }, // BaseObject_Z
        { &lbl_80374F98, 0 }, // Activable_Z
        { &lbl_80374FA0, 0 }, // Manipulator_Z
        { &lbl_80374FA8, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802BB008 = {
    {
        { &lbl_80374F90, 0 }, // BaseObject_Z
        { &lbl_80374F98, 0 }, // Activable_Z
        { &lbl_80374FA0, 0 }, // Manipulator_Z
        { &lbl_80374FA8, 0 }, // ObjectMove_Z
        { &lbl_80374FB0, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802BB034 = {
    {
        { &lbl_80374F88, 792 }, // CFSM
        { &lbl_80374F90, 0 }, // BaseObject_Z
        { &lbl_80374F98, 0 }, // Activable_Z
        { &lbl_80374FA0, 0 }, // Manipulator_Z
        { &lbl_80374FA8, 0 }, // ObjectMove_Z
        { &lbl_80374FB0, 0 }, // ObjectThrow_Z
        { &lbl_80374FB8, 0 }, // LodMove_Z
    }, 0
};

}
