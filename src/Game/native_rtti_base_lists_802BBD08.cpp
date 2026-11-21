#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateSimpleIdle.
NativeRuntimeBaseList<3> lbl_802BBD08 = {
    {
        { &lbl_80375088, 0 }, // CState
        { &lbl_80375090, 0 }, // CStateScriptBase
        { &lbl_80375098, 0 }, // CStateSimpleBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A2DCCFv();
void fn_8009FF18();
void fn_8009FF54();
void fn_800A4E10();
void fn_800A4E50();
}

extern "C" __declspec(section ".data") const void* const lbl_802BBD24[7] __attribute__((aligned(4))) = {
    &lbl_80375148,
    0,
    (const void*)__dt__15Object_800A2DCCFv,
    (const void*)fn_8009FF18,
    (const void*)fn_8009FF54,
    (const void*)fn_800A4E50,
    (const void*)fn_800A4E10,
};

