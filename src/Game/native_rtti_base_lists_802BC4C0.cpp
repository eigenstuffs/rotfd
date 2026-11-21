#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateMediumAttack.
NativeRuntimeBaseList<3> lbl_802BC4C0 = {
    {
        { &lbl_80375238, 0 }, // CState
        { &lbl_80375240, 0 }, // CStateScriptBase
        { &lbl_80375248, 0 }, // CStateMediumBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A479CFv();
void fn_800A45A4();
void fn_800A4D2C();
void fn_800A4D4C();
void fn_800A4D8C();
}

extern "C" __declspec(section ".data") const void* const lbl_802BC4DC[7] __attribute__((aligned(4))) = {
    &lbl_80375258,
    0,
    (const void*)__dt__15Object_800A479CFv,
    (const void*)fn_800A45A4,
    (const void*)fn_800A4D2C,
    (const void*)fn_800A4D8C,
    (const void*)fn_800A4D4C,
};

