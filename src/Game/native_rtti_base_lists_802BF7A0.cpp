#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BF7A0 = {
    {
        { &lbl_803756D8, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BF7AC = {
    {
        { &lbl_803756D8, 0 }, // BaseObject_Z
        { &lbl_803756E0, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for DisplayStaticImage.
NativeRuntimeBaseList<3> lbl_802BF7C0 = {
    {
        { &lbl_803756D8, 0 }, // BaseObject_Z
        { &lbl_803756E0, 0 }, // Activable_Z
        { &lbl_803756E8, 0 }, // Manipulator_Z
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void fn_800C4334();
void fn_800C43E4();
void fn_800C4510();
void fn_800C4570();
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

extern "C" __declspec(section ".data") const void* const lbl_802BF7DC[17] __attribute__((aligned(4))) = {
    &lbl_803756F0,
    0,
    (const void*)fn_800C4334,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800C43E4,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)slot20__11Activable_ZFv,
    (const void*)slot24__11Activable_ZFv,
    (const void*)slot28__11Activable_ZFv,
    (const void*)slot2C__13Manipulator_ZFf,
    (const void*)slot30__13Manipulator_ZFv,
    (const void*)slot34__13Manipulator_ZFv,
    (const void*)fn_800C4570,
    (const void*)slot3C__13Manipulator_ZFv,
    (const void*)fn_800C4510,
};

