#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802B8360 = {
    {
        { &lbl_80374968, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802B836C = {
    {
        { &lbl_80374968, 0 }, // BaseObject_Z
        { &lbl_80374970, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for CameraEngine_Z.
NativeRuntimeBaseList<3> lbl_802B8380 = {
    {
        { &lbl_80374968, 0 }, // BaseObject_Z
        { &lbl_80374970, 0 }, // Activable_Z
        { &lbl_80374978, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for CameraEngineZone_Z.
NativeRuntimeBaseList<4> lbl_802B839C = {
    {
        { &lbl_80374968, 0 }, // BaseObject_Z
        { &lbl_80374970, 0 }, // Activable_Z
        { &lbl_80374978, 0 }, // Manipulator_Z
        { &lbl_80374980, 0 }, // CameraEngine_Z
    }, 0
};

// Base hierarchy for CCamera.
NativeRuntimeBaseList<5> lbl_802B83C0 = {
    {
        { &lbl_80374968, 0 }, // BaseObject_Z
        { &lbl_80374970, 0 }, // Activable_Z
        { &lbl_80374978, 0 }, // Manipulator_Z
        { &lbl_80374980, 0 }, // CameraEngine_Z
        { &lbl_80374988, 0 }, // CameraEngineZone_Z
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8007D284Fv();
void __dt__4CFSMFv();
void __dt__15Object_8007F3DCFv();
void fn_800761F0();
void fn_8007B5AC();
void configure__4CFSMFi();
void reset__4CFSMFv();
void configureCallbacks__4CFSMFv();
void fn_8007F4A8();
void fn_80235C28();
void fn_80235D38();
void fn_80235D54();
void fn_80235DC0();
void fn_80235EBC();
void fn_80235EF4();
void fn_80236120();
void fn_802377B4();
void fn_80237C40();
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

extern "C" __declspec(section ".data") const void* const lbl_802B83EC[23] __attribute__((aligned(4))) = {
    &lbl_80374990,
    0,
    (const void*)__dt__15Object_8007D284Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_80237C40,
    (const void*)fn_80235C28,
    (const void*)slot20__11Activable_ZFv,
    (const void*)slot24__11Activable_ZFv,
    (const void*)slot28__11Activable_ZFv,
    (const void*)slot2C__13Manipulator_ZFf,
    (const void*)slot30__13Manipulator_ZFv,
    (const void*)fn_800761F0,
    (const void*)fn_8007B5AC,
    (const void*)slot3C__13Manipulator_ZFv,
    (const void*)fn_802377B4,
    (const void*)fn_80235DC0,
    (const void*)fn_80236120,
    (const void*)fn_80235EF4,
    (const void*)fn_80235D54,
    (const void*)fn_80235EBC,
    (const void*)fn_80235D38,
};

extern "C" __declspec(section ".data") const void* const __vt__4CFSM[6] __attribute__((aligned(4))) = {
    &lbl_80374998,
    0,
    (const void*)__dt__4CFSMFv,
    (const void*)configureCallbacks__4CFSMFv,
    (const void*)configure__4CFSMFi,
    (const void*)reset__4CFSMFv,
};

extern "C" __declspec(section ".data") const void* const lbl_802B8460[4] __attribute__((aligned(4))) = {
    &lbl_803749A0,
    0,
    (const void*)__dt__15Object_8007F3DCFv,
    (const void*)fn_8007F4A8,
};

