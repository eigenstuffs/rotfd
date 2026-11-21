#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateSimpleAttackCharge.
NativeRuntimeBaseList<3> lbl_802BBB80 = {
    {
        { &lbl_80375088, 0 }, // CState
        { &lbl_80375090, 0 }, // CStateScriptBase
        { &lbl_80375098, 0 }, // CStateSimpleBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A2988Fv();
void fn_800A0D3C();
void fn_800A0E1C();
void fn_800A4E10();
void fn_800A4E50();
}

extern "C" __declspec(section ".data") const void* const lbl_802BBB9C[7] __attribute__((aligned(4))) = {
    &lbl_80375110,
    0,
    (const void*)__dt__15Object_800A2988Fv,
    (const void*)fn_800A0D3C,
    (const void*)fn_800A0E1C,
    (const void*)fn_800A4E50,
    (const void*)fn_800A4E10,
};

