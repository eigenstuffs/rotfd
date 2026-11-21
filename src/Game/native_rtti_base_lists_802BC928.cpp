#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BC928 = {
    {
        { &lbl_80375310, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BC934 = {
    {
        { &lbl_80375310, 0 }, // BaseObject_Z
        { &lbl_80375318, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ManipulatorDraw_Z.
NativeRuntimeBaseList<3> lbl_802BC948 = {
    {
        { &lbl_80375310, 0 }, // BaseObject_Z
        { &lbl_80375318, 0 }, // Activable_Z
        { &lbl_80375320, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for CHudData.
NativeRuntimeBaseList<4> lbl_802BC964 = {
    {
        { &lbl_80375310, 0 }, // BaseObject_Z
        { &lbl_80375318, 0 }, // Activable_Z
        { &lbl_80375320, 0 }, // Manipulator_Z
        { &lbl_80375328, 0 }, // ManipulatorDraw_Z
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A6090Fv();
void __dt__24ManipulatorDraw_802BC9D0Fv();
void fn_800A4F2C();
void fn_800A6D90();
void fn_800A7930();
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

extern "C" __declspec(section ".data") const void* const __vt__15Object_800A6090[18] __attribute__((aligned(4))) = {
    &lbl_80375330,
    0,
    (const void*)__dt__15Object_800A6090Fv,
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
    (const void*)fn_800A6D90,
    (const void*)slot3C__13Manipulator_ZFv,
    (const void*)fn_800A7930,
    (const void*)fn_800A4F2C,
};

extern "C" __declspec(section ".data") const void* const __vt__24ManipulatorDraw_802BC9D0[18] __attribute__((aligned(4))) = {
    &lbl_80375328,
    0,
    (const void*)__dt__24ManipulatorDraw_802BC9D0Fv,
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
    0,
    (const void*)slot3C__13Manipulator_ZFv,
    0,
    0,
};

