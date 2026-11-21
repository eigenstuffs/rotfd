#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateScriptBase.
NativeRuntimeBaseList<1> lbl_802BC8E8 = {
    {
        { &lbl_803752F0, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateComplexBase.
NativeRuntimeBaseList<2> lbl_802BC8F4 = {
    {
        { &lbl_803752F0, 0 }, // CState
        { &lbl_803752F8, 0 }, // CStateScriptBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A39BCFv();
void fn_800A4EAC();
void fn_800A4ECC();
void fn_800A4EEC();
void fn_800A4F0C();
}

extern "C" __declspec(section ".data") const void* const lbl_802BC908[8] __attribute__((aligned(4))) = {
    &lbl_80375300,
    0,
    (const void*)__dt__15Object_800A39BCFv,
    (const void*)fn_800A4EEC,
    (const void*)fn_800A4EAC,
    (const void*)fn_800A4F0C,
    (const void*)fn_800A4ECC,
    0,
};

