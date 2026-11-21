#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BD740 = {
    {
        { &lbl_80375460, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BD74C = {
    {
        { &lbl_80375460, 0 }, // BaseObject_Z
        { &lbl_80375468, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ManipulatorDraw_Z.
NativeRuntimeBaseList<3> lbl_802BD760 = {
    {
        { &lbl_80375460, 0 }, // BaseObject_Z
        { &lbl_80375468, 0 }, // Activable_Z
        { &lbl_80375470, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for Menu_Z.
NativeRuntimeBaseList<4> lbl_802BD77C = {
    {
        { &lbl_80375460, 0 }, // BaseObject_Z
        { &lbl_80375468, 0 }, // Activable_Z
        { &lbl_80375470, 0 }, // Manipulator_Z
        { &lbl_80375478, 0 }, // ManipulatorDraw_Z
    }, 0
};

// Base hierarchy for Menu2D.
NativeRuntimeBaseList<5> lbl_802BD7A0 = {
    {
        { &lbl_80375460, 0 }, // BaseObject_Z
        { &lbl_80375468, 0 }, // Activable_Z
        { &lbl_80375470, 0 }, // Manipulator_Z
        { &lbl_80375478, 0 }, // ManipulatorDraw_Z
        { &lbl_80375480, 0 }, // Menu_Z
    }, 0
};

// Base hierarchy for OptionsMenuMove.
NativeRuntimeBaseList<6> lbl_802BD7CC = {
    {
        { &lbl_80375460, 0 }, // BaseObject_Z
        { &lbl_80375468, 0 }, // Activable_Z
        { &lbl_80375470, 0 }, // Manipulator_Z
        { &lbl_80375478, 0 }, // ManipulatorDraw_Z
        { &lbl_80375480, 0 }, // Menu_Z
        { &lbl_80375488, 0 }, // Menu2D
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800B4F28Fv();
void __dt__15Object_800B5254Fv();
void fn_800B0468();
void fn_800B1C9C();
void fn_800B2F28();
void fn_800B31B8();
void fn_800B423C();
void fn_800B4628();
void fn_800B4D1C();
void fn_800B4E48();
void fn_800B5068();
void fn_800B5188();
void fn_8021D7AC();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot20__11Activable_ZFv();
void slot24__11Activable_ZFv();
void slot28__11Activable_ZFv();
void slot2C__13Manipulator_ZFf();
void slot30__13Manipulator_ZFv();
void slot34__13Manipulator_ZFv();
void slot3C__13Manipulator_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802BD800[22] __attribute__((aligned(4))) = {
    &lbl_80375490,
    0,
    (const void*)__dt__15Object_800B5254Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8021D7AC,
    (const void*)fn_800B2F28,
    (const void*)slot20__11Activable_ZFv,
    (const void*)slot24__11Activable_ZFv,
    (const void*)slot28__11Activable_ZFv,
    (const void*)slot2C__13Manipulator_ZFf,
    (const void*)slot30__13Manipulator_ZFv,
    (const void*)slot34__13Manipulator_ZFv,
    (const void*)fn_800B5068,
    (const void*)slot3C__13Manipulator_ZFv,
    (const void*)fn_800B1C9C,
    (const void*)fn_800B4D1C,
    (const void*)fn_800B5188,
    (const void*)fn_800B423C,
    (const void*)fn_800B0468,
    (const void*)fn_800B31B8,
};

extern "C" __declspec(section ".data") const void* const __vt__15Object_800B4F28[22] __attribute__((aligned(4))) = {
    &lbl_80375488,
    0,
    (const void*)__dt__15Object_800B4F28Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8021D7AC,
    (const void*)fn_800B2F28,
    (const void*)slot20__11Activable_ZFv,
    (const void*)slot24__11Activable_ZFv,
    (const void*)slot28__11Activable_ZFv,
    (const void*)slot2C__13Manipulator_ZFf,
    (const void*)slot30__13Manipulator_ZFv,
    (const void*)slot34__13Manipulator_ZFv,
    (const void*)fn_800B4628,
    (const void*)slot3C__13Manipulator_ZFv,
    (const void*)fn_800B1C9C,
    (const void*)fn_800B4D1C,
    (const void*)fn_800B4E48,
    (const void*)fn_800B423C,
    (const void*)fn_800B0468,
    (const void*)fn_800B31B8,
};

