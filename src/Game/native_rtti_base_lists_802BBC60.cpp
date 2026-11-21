#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateSimpleFlee.
NativeRuntimeBaseList<3> lbl_802BBC60 = {
    {
        { &lbl_80375088, 0 }, // CState
        { &lbl_80375090, 0 }, // CStateScriptBase
        { &lbl_80375098, 0 }, // CStateSimpleBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A2BF8Fv();
void fn_800A0678();
void fn_800A06C0();
void fn_800A0810();
void fn_800A4E10();
}

extern "C" __declspec(section ".data") const void* const lbl_802BBC7C[7] __attribute__((aligned(4))) = {
    &lbl_80375130,
    0,
    (const void*)__dt__15Object_800A2BF8Fv,
    (const void*)fn_800A0678,
    (const void*)fn_800A06C0,
    (const void*)fn_800A0810,
    (const void*)fn_800A4E10,
};

