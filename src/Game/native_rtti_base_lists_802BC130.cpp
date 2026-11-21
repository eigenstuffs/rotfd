#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateComplexIdle.
NativeRuntimeBaseList<3> lbl_802BC130 = {
    {
        { &lbl_803751B0, 0 }, // CState
        { &lbl_803751B8, 0 }, // CStateScriptBase
        { &lbl_803751C0, 0 }, // CStateComplexBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A3F18Fv();
void fn_800A3A48();
void fn_800A4EAC();
void fn_800A4ECC();
void fn_800A4F0C();
}

extern "C" __declspec(section ".data") const void* const lbl_802BC14C[7] __attribute__((aligned(4))) = {
    &lbl_803751E0,
    0,
    (const void*)__dt__15Object_800A3F18Fv,
    (const void*)fn_800A3A48,
    (const void*)fn_800A4EAC,
    (const void*)fn_800A4F0C,
    (const void*)fn_800A4ECC,
};

