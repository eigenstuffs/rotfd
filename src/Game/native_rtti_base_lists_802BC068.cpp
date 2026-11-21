#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateScriptBase.
NativeRuntimeBaseList<1> lbl_802BC068 = {
    {
        { &lbl_803751B0, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateComplexBase.
NativeRuntimeBaseList<2> lbl_802BC074 = {
    {
        { &lbl_803751B0, 0 }, // CState
        { &lbl_803751B8, 0 }, // CStateScriptBase
    }, 0
};

// Base hierarchy for CStateComplexFlee.
NativeRuntimeBaseList<3> lbl_802BC088 = {
    {
        { &lbl_803751B0, 0 }, // CState
        { &lbl_803751B8, 0 }, // CStateScriptBase
        { &lbl_803751C0, 0 }, // CStateComplexBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A3D44Fv();
void fn_800A3CB8();
void fn_800A4EAC();
void fn_800A4ECC();
void fn_800A4F0C();
}

extern "C" __declspec(section ".data") const void* const lbl_802BC0A4[7] __attribute__((aligned(4))) = {
    &lbl_803751C8,
    0,
    (const void*)__dt__15Object_800A3D44Fv,
    (const void*)fn_800A3CB8,
    (const void*)fn_800A4EAC,
    (const void*)fn_800A4F0C,
    (const void*)fn_800A4ECC,
};

