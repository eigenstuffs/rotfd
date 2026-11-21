#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BF650 = {
    {
        { &lbl_80375688, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BF65C = {
    {
        { &lbl_80375688, 0 }, // BaseObject_Z
        { &lbl_80375690, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ManipulatorDraw_Z.
NativeRuntimeBaseList<3> lbl_802BF670 = {
    {
        { &lbl_80375688, 0 }, // BaseObject_Z
        { &lbl_80375690, 0 }, // Activable_Z
        { &lbl_80375698, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for CMsgBoxManipulator.
NativeRuntimeBaseList<4> lbl_802BF68C = {
    {
        { &lbl_80375688, 0 }, // BaseObject_Z
        { &lbl_80375690, 0 }, // Activable_Z
        { &lbl_80375698, 0 }, // Manipulator_Z
        { &lbl_803756A0, 0 }, // ManipulatorDraw_Z
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800C224CFv();
void fn_800C2378();
void fn_800C23F8();
void fn_800C2418();
void fn_800C28C0();
void fn_800C293C();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot20__11Activable_ZFv();
void slot24__11Activable_ZFv();
void slot28__11Activable_ZFv();
void slot2C__13Manipulator_ZFf();
void slot30__13Manipulator_ZFv();
void slot3C__13Manipulator_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802BF6B0[18] __attribute__((aligned(4))) = {
    &lbl_803756A8,
    0,
    (const void*)__dt__15Object_800C224CFv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800C2378,
    (const void*)fn_800C2418,
    (const void*)slot20__11Activable_ZFv,
    (const void*)slot24__11Activable_ZFv,
    (const void*)slot28__11Activable_ZFv,
    (const void*)slot2C__13Manipulator_ZFf,
    (const void*)slot30__13Manipulator_ZFv,
    (const void*)fn_800C23F8,
    (const void*)fn_800C28C0,
    (const void*)slot3C__13Manipulator_ZFv,
    (const void*)fn_800C293C,
    0,
};

