#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateSimpleReturn.
NativeRuntimeBaseList<3> lbl_802BBBF0 = {
    {
        { &lbl_80375088, 0 }, // CState
        { &lbl_80375090, 0 }, // CStateScriptBase
        { &lbl_80375098, 0 }, // CStateSimpleBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A2AC0Fv();
void fn_800A0A2C();
void fn_800A0A84();
void fn_800A0C68();
void fn_800A4E10();
}

extern "C" __declspec(section ".data") const void* const lbl_802BBC0C[7] __attribute__((aligned(4))) = {
    &lbl_80375120,
    0,
    (const void*)__dt__15Object_800A2AC0Fv,
    (const void*)fn_800A0A2C,
    (const void*)fn_800A0A84,
    (const void*)fn_800A0C68,
    (const void*)fn_800A4E10,
};

