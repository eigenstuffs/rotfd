#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateSimpleJump.
NativeRuntimeBaseList<3> lbl_802BBB10 = {
    {
        { &lbl_80375088, 0 }, // CState
        { &lbl_80375090, 0 }, // CStateScriptBase
        { &lbl_80375098, 0 }, // CStateSimpleBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A2850Fv();
void fn_800A10A4();
void fn_800A11A0();
void fn_800A1228();
void fn_800A4E10();
}

extern "C" __declspec(section ".data") const void* const lbl_802BBB2C[7] __attribute__((aligned(4))) = {
    &lbl_80375100,
    0,
    (const void*)__dt__15Object_800A2850Fv,
    (const void*)fn_800A10A4,
    (const void*)fn_800A11A0,
    (const void*)fn_800A1228,
    (const void*)fn_800A4E10,
};

