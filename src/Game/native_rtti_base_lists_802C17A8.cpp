#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802C17A8 = {
    {
        { &lbl_803758E0, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802C17B4 = {
    {
        { &lbl_803758E0, 0 }, // BaseObject_Z
        { &lbl_803758E8, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ManipulatorDraw_Z.
NativeRuntimeBaseList<3> lbl_802C17C8 = {
    {
        { &lbl_803758E0, 0 }, // BaseObject_Z
        { &lbl_803758E8, 0 }, // Activable_Z
        { &lbl_803758F0, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for LoadingScreen.
NativeRuntimeBaseList<4> lbl_802C17E4 = {
    {
        { &lbl_803758E0, 0 }, // BaseObject_Z
        { &lbl_803758E8, 0 }, // Activable_Z
        { &lbl_803758F0, 0 }, // Manipulator_Z
        { &lbl_803758F8, 0 }, // ManipulatorDraw_Z
    }, 0
};

}

// Adjacent native method and runtime-base records.

extern "C" {
void fn_800CB000();
void fn_800CB5A4();
void fn_800CB5F4();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot18__11Activable_ZFv();
void slot1C__12BaseObject_ZFv();
void slot20__11Activable_ZFv();
void slot24__11Activable_ZFv();
void slot28__11Activable_ZFv();
void slot2C__13Manipulator_ZFf();
void slot30__13Manipulator_ZFv();
void slot34__13Manipulator_ZFv();
void slot3C__13Manipulator_ZFv();
}

extern "C" __declspec(section ".data") const void* const __vt__15Object_800CB000[18] __attribute__((aligned(4))) = {
    &lbl_80375900,
    0,
    (const void*)fn_800CB000,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)slot18__11Activable_ZFv,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)slot20__11Activable_ZFv,
    (const void*)slot24__11Activable_ZFv,
    (const void*)slot28__11Activable_ZFv,
    (const void*)slot2C__13Manipulator_ZFf,
    (const void*)slot30__13Manipulator_ZFv,
    (const void*)slot34__13Manipulator_ZFv,
    (const void*)fn_800CB5A4,
    (const void*)slot3C__13Manipulator_ZFv,
    (const void*)fn_800CB5F4,
    0,
};

