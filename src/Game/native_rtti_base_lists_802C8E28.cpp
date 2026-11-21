#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802C8E28 = {
    {
        { &lbl_80375B48, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802C8E34 = {
    {
        { &lbl_80375B48, 0 }, // BaseObject_Z
        { &lbl_80375B50, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ManipulatorDraw_Z.
NativeRuntimeBaseList<3> lbl_802C8E48 = {
    {
        { &lbl_80375B48, 0 }, // BaseObject_Z
        { &lbl_80375B50, 0 }, // Activable_Z
        { &lbl_80375B58, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for CNoCamDraw.
NativeRuntimeBaseList<4> lbl_802C8E64 = {
    {
        { &lbl_80375B48, 0 }, // BaseObject_Z
        { &lbl_80375B50, 0 }, // Activable_Z
        { &lbl_80375B58, 0 }, // Manipulator_Z
        { &lbl_80375B60, 0 }, // ManipulatorDraw_Z
    }, 0
};

}

// Adjacent native method and runtime-base records.

extern "C" {
void fn_800E6F84();
void fn_800E7024();
void fn_800E7028();
void fn_800E745C();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot1C__12BaseObject_ZFv();
void slot20__11Activable_ZFv();
void slot24__11Activable_ZFv();
void slot28__11Activable_ZFv();
void slot2C__13Manipulator_ZFf();
void slot30__13Manipulator_ZFv();
void slot34__13Manipulator_ZFv();
void slot3C__13Manipulator_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802C8E88[18] __attribute__((aligned(4))) = {
    &lbl_80375B68,
    0,
    (const void*)fn_800E745C,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800E6F84,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)slot20__11Activable_ZFv,
    (const void*)slot24__11Activable_ZFv,
    (const void*)slot28__11Activable_ZFv,
    (const void*)slot2C__13Manipulator_ZFf,
    (const void*)slot30__13Manipulator_ZFv,
    (const void*)slot34__13Manipulator_ZFv,
    (const void*)fn_800E7024,
    (const void*)slot3C__13Manipulator_ZFv,
    (const void*)fn_800E7028,
    0,
};

extern "C" __declspec(section ".data") const void* const lbl_802C8ED0[3] __attribute__((aligned(4))) = {
    0,
    (const void*)0x00000094,
    (const void*)0x00000008,
};

extern "C" __declspec(section ".data") const void* const lbl_802C8EDC[3] __attribute__((aligned(4))) = {
    0,
    (const void*)0x00000098,
    (const void*)0x00000008,
};

